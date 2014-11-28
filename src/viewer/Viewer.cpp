/*
 * @(#) Viewer.cpp   1.0   Nov 27, 2014
 *
 * Joshua Auerbach (joshua.auerbach@epfl.ch)
 *
 * The ROBOGEN Framework
 * Copyright © 2014 Joshua Auerbach
 *
 * Laboratory of Intelligent Systems, EPFL
 *
 * This file is part of the ROBOGEN Framework.
 *
 * The ROBOGEN Framework is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License (GPL)
 * as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @(#) $Id$
 */

#include "viewer/Viewer.h"
#include "RenderModels.h"
#include "utils/RobogenUtils.h"

#include <boost/format.hpp>
#include <sstream>
#include <osgDB/WriteFile>

namespace robogen{

class SnapImageDrawCallback : public osg::Camera::DrawCallback {
public:

	SnapImageDrawCallback()
	{
		_snapImageOnNextFrame = false;
	}

	void setFileName(const std::string& filename) { _filename = filename; }
	const std::string& getFileName() const { return _filename; }

	void setSnapImageOnNextFrame(bool flag) { _snapImageOnNextFrame = flag; }
	bool getSnapImageOnNextFrame() const { return _snapImageOnNextFrame; }

	virtual void operator () (const osg::Camera& camera) const
	{
		if (!_snapImageOnNextFrame) return;

		int x,y,width,height;
		x = camera.getViewport()->x();
		y = camera.getViewport()->y();
		width = camera.getViewport()->width();
		height = camera.getViewport()->height();

		osg::ref_ptr<osg::Image> image = new osg::Image;
		image->readPixels(x,y,width,height,GL_RGB,GL_UNSIGNED_BYTE);

		if (osgDB::writeImageFile(*image,_filename))
		{
		std::cout << "Saved screen image to `"<<_filename<<"`"<< std::endl;
		}

		_snapImageOnNextFrame = false;
	}

protected:

	std::string _filename;
	mutable bool _snapImageOnNextFrame;


};

Viewer::Viewer(bool startPaused) :
	frameCount(0) {
	// ---------------------------------------
	// OSG Initialization
	// ---------------------------------------

	//Creating the viewer
	this->viewer = new osgViewer::Viewer();
	this->viewer->setUpViewInWindow(200, 200, 800, 600);
	this->keyboardEvent = osg::ref_ptr<KeyboardHandler>(
			new KeyboardHandler(startPaused));

	this->viewer->addEventHandler(keyboardEvent.get());

	// Camera
	this->camera = viewer->getCamera();

	//Creating the root node
	this->root = osg::ref_ptr<osg::Group>(new osg::Group);

}

Viewer::~Viewer() {
	delete this->viewer;
}

bool Viewer::configureScene(std::vector<boost::shared_ptr<Model> > bodyParts,
		boost::shared_ptr<Scenario> scenario) {

	std::vector<boost::shared_ptr<RenderModel> > renderModels;

	for (unsigned int i = 0; i < bodyParts.size(); ++i) {
		boost::shared_ptr<RenderModel> renderModel =
				RobogenUtils::createRenderModel(bodyParts[i]);
		if (renderModel == NULL) {
			std::cout
			<< "Cannot create a render model for model "
			<< i << std::endl;
			return false;
		}

		if (!renderModel->initRenderModel()) {
			std::cout
			<< "Cannot initialize a render model for one of the components. "
			<< std::endl
			<< "Please check that the models/ folder is in the same folder of this executable."
			<< std::endl;
			return false;
		}
		renderModels.push_back(renderModel);
		this->root->addChild(renderModels[i]->getRootNode());
	}

	// Terrain render model
	boost::shared_ptr<TerrainRender> terrainRender(
			new TerrainRender(scenario->getTerrain()));
	this->root->addChild(terrainRender->getRootNode());

	// Obstacles render model
	const std::vector<boost::shared_ptr<BoxObstacle> >& obstacles =
			scenario->getObstacles();
	for (unsigned int i = 0; i < obstacles.size(); ++i) {
		boost::shared_ptr<BoxObstacleRender> obstacleRender(
				new BoxObstacleRender(obstacles[i]));
		this->root->addChild(obstacleRender->getRootNode());
	}

	// ---------------------------------------
	// Setup OSG viewer
	// ---------------------------------------

	this->viewer->setSceneData(root.get());

	this->viewer->realize();

	if (!this->viewer->getCameraManipulator()
			&& this->viewer->getCamera()->getAllowEventFocus()) {
		this->viewer->setCameraManipulator(
				new osgGA::TrackballManipulator());
	}

	this->viewer->setReleaseContextAtEndOfFrameHint(false);

	std::cout << "Press P to pause/unpause the simulation." << std::endl;
	std::cout << "Press Q to quit the visualizer." << std::endl;

	return true;

}

bool Viewer::done() {
	return this->viewer->done();
}

void Viewer::frame() {
	this->viewer->frame();
}

void Viewer::initializeRecording(std::string recordDirectoryName) {
	osg::ref_ptr<SnapImageDrawCallback> snapImageDrawCallback = new
												SnapImageDrawCallback();
	this->viewer->getCamera()->setPostDrawCallback(
			snapImageDrawCallback.get());
	this->recordDirectoryName = recordDirectoryName;
}

void Viewer::record() {

	osg::ref_ptr<SnapImageDrawCallback> snapImageDrawCallback =
			dynamic_cast<SnapImageDrawCallback*>
			(viewer->getCamera()->getPostDrawCallback());

	if(snapImageDrawCallback.get()) {
		std::stringstream ss;
		ss << this->recordDirectoryName << "/" <<
				boost::format("%|04|")%this->frameCount << ".jpg";
		snapImageDrawCallback->setFileName(ss.str());
		snapImageDrawCallback->setSnapImageOnNextFrame(true);
		this->frameCount++;
	}

}

bool Viewer::isPaused() {
	return this->keyboardEvent->isPaused();
}

} /* namespace robogen */
