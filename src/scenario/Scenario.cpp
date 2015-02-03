/*
 * @(#) Scenario.cpp   1.0   Mar 13, 2013
 *
 * Andrea Maesani (andrea.maesani@epfl.ch)
 *
 * The ROBOGEN Framework
 * Copyright © 2012-2013 Andrea Maesani
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
#include <iostream>
#include <math.h>
#include "config/RobogenConfig.h"
#include "config/TerrainConfig.h"
#include "model/objects/BoxObstacle.h"
#include "scenario/Scenario.h"
#include "scenario/Terrain.h"
#include "Robot.h"

namespace robogen {

Scenario::Scenario(boost::shared_ptr<RobogenConfig> robogenConfig) :
		robogenConfig_(robogenConfig), startPositionId_(0) {

}

Scenario::~Scenario() {

}

bool Scenario::init(dWorldID odeWorld, dSpaceID odeSpace,
		std::vector< boost::shared_ptr<Robot> > robots) {

	odeWorld_ = odeWorld;
	odeSpace_ = odeSpace;

	// Don't know how this is used - just assign first robot.
	robot_ = robots[0];

	// Setup terrain
	boost::shared_ptr<TerrainConfig> terrainConfig =
			robogenConfig_->getTerrainConfig();

	float terrainLength = terrainConfig->getLength();
	float terrainWidth = terrainConfig->getWidth();
	float radius = 0.2 * std::min(terrainLength, terrainWidth);

	terrain_.reset(new Terrain(odeWorld_, odeSpace_));
	if (terrainConfig->isFlat()) {
		terrain_->initFlat(terrainConfig->getLength(),
				terrainConfig->getWidth());
	} else {
		terrain_->initRough(terrainConfig->getHeightFieldFileName(),
				terrainConfig->getLength(), terrainConfig->getWidth(),
				terrainConfig->getHeight());
	}

	// Setup robot position
	double minX = 0;
	double maxX = 0;
	double minY = 0;
	double maxY = 0;
	double minZ = 0;
	double maxZ = 0;

	unsigned int nBots = robots.size();
	double shift = 2.0 * M_PI / nBots;
	for (unsigned int i = 0; i < nBots; ++i) {
		boost::shared_ptr<Robot> robot = robots[i];

		// Starting position and orientation
		// Like the other stress test, I will just position the bots on a circle
		// with the radius calculated further above.
		// I'll need an actual working controller to have them move into each
		// other though..
		double angle = i * shift;
		double x = radius * cos(angle);
		double y = radius * sin(angle);
		osg::Vec2 startingPosition(x, y);

		std::cout << "angle: " << angle << std::endl;
		std::cout << "i: " << i << ", x: " << x << " y: " << y << std::endl;

		float startingAzimuth = 1.5 * M_PI - angle;
		osg::Quat roboRot;
		roboRot.makeRotate(startingAzimuth, osg::Vec3(0,0,1));

		robot->rotateRobot(roboRot);
		robot->getBB(minX, maxX, minY, maxY, minZ, maxZ);
		robot->translateRobot(
				osg::Vec3(startingPosition.x() - (maxX - minX) / 2,
						startingPosition.y() - (maxY - minY) / 2,
						terrainConfig->getHeight() + inMm(2) - minZ));
	}


	// Removed obstacles code here - if you want it back, check master branch
	// This also means I removed the bounding boxes, etc

	return true;
}

boost::shared_ptr<StartPosition> Scenario::getCurrentStartPosition() {
	return robogenConfig_->getStartingPos()->getStartPosition(
			startPositionId_);
}

void Scenario::prune(){
	odeWorld_ = 0;
	odeSpace_ = 0;
	robot_.reset();
	terrain_.reset();
	obstacles_.clear();
}

std::vector<boost::shared_ptr<BoxObstacle> > Scenario::getObstacles() {
	return obstacles_;
}

boost::shared_ptr<Terrain> Scenario::getTerrain() {
	return terrain_;
}

boost::shared_ptr<Robot> Scenario::getRobot() {
	return robot_;
}

boost::shared_ptr<RobogenConfig> Scenario::getRobogenConfig() {
	return robogenConfig_;
}

void Scenario::setStartingPosition(int id) {
	startPositionId_ = id;
}

boost::shared_ptr<Environment> Scenario::getEnvironment() {
	return environment_;
}

void Scenario::setEnvironment(boost::shared_ptr<Environment> env) {
	environment_ = env;
}

}
