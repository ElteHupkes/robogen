/*
 * @(#) Model.h   1.0   Feb 8, 2013
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
#ifndef SDFB_MODEL_H_
#define SDFB_MODEL_H_

#include <iostream>
#include <map>
#include <stdexcept>

// Utility defines taken from Robogen.h
#define inMm(x) (x/1000.0)
#define inGrams(x) (x/1000.0)

// sdfbuilder
#include <gazebo/sdf/Types.h>
#include <gazebo/sdf/Parts.h>

namespace sdf_builder {

/**
 * Gazebo model class, derives SDF models from the functionality
 * that is currently used to place the models in the ODE world.
 * Please note that I'm taking the Model terminology from Robogen,
 * a Robogen model will *NOT* map to an SDF Model (rather an SDF
 * model will be a collection of Robogen models).
 *
 * I'll initially approach this as follows. Each Model defines several things:
 * - A set of links, with a geometry, inertia, position and
 *   orientation within the model they specify. I'll later add "visual
 *   representation" to this list.
 * - A set of joints, also with a pose / type / orientation and possibly
 *   other properties. These joints will also specify which of the links
 *   within the model they connect. I can use the handy property that there
 *   are only moving joints *within* the objects; the rest of the joints
 *   are actually fixed. So I'll never have to specify a joint to a body
 *   part in another "model".
 *
 * Fixed joints to attach models to one another will be automatically added
 * by the Robot builder.
 *
 * Ideally I'd reduce the number of links in the model by combining
 * fixed collision objects. The problem here is the inertia tensor, which
 * would then have to be applied to the combined objects.
 * I might be able to do this for fixed connections
 * within models, since I have the specifics there and could probably
 * calculate the inertia tensor with MeshLab, for instance. To do it for
 * larger chunks I'd need inertia tensors for every perceivable combination,
 * which I reckon is rather undoable.
 */
class Model {

public:

	/**
	 * Constructor
	 */
	Model(std::string id);

	/**
	 * Destructor
	 */
	virtual ~Model();

	/**
	 * @return true if the model initialization completed successfully
	 */
	virtual bool initModel() = 0;

	/**
	 * @return id string of the part
	 */
	const std::string &getId();

	/**
	 * @return the body corresponding to the selected slot
	 */
	virtual LinkPtr getSlot(unsigned int i) = 0;

	/**
	 * @return the slot position, in world coordinates
	 */
	virtual Vector3 getSlotPosition(unsigned int i) = 0;

	/**
	 * @return the slot axis (normal to the slot)
	 */
	virtual Vector3 getSlotAxis(unsigned int i) = 0;

	/**
	 * Tangent to the slot surface, defines the zero rotation orientation
	 * on that slot
	 */
	virtual Vector3 getSlotOrientation(unsigned int i) = 0;

	/**
	 * @return the root body
	 */
	virtual LinkPtr getRoot() = 0;

	/**
	 * @return the position of the root part
	 */
	Vector3 getRootPosition();

	/**
	 * @return the attitude of the root part (a quaternion)
	 */
	Quaternion getRootAttitude();

	/**
	 * @return the position of the specified body
	 */
	Vector3 getBodyPosition(int id);

	/**
	 * @return the attitude of the specified body
	 */
	Quaternion getBodyAttitude(int id);

	/**
	 * Sets the position of the root part.
	 * Will force all the other bodies to translate accordingly.
	 */
	void setRootPosition(const Vector3& pos);

	/**
	 * Translate the root part of the specified amount
	 * Will force all the other bodies to translate accordingly.
	 */
	void translateRootPosition(const osg::Vec3& translation);

	/**
	 * Sets the attitude of the root part (a quaternion).
	 * Will force all the other bodies to rotate accordingly.
	 */
	void setRootAttitude(const osg::Quat& quat);

	/**
	 * @return the position of the given body
	 */
	Vector3 getPosition(LinkPtr body);

	/**
	 * @return the attitude of the given body
	 */
	Quaternion getAttitude(LinkPtr body);

	/**
	 * @return the specified body
	 */
	LinkPtr getLink(int id);

	/**
	 * @return all the bodies belonging to this model
	 */
	std::vector<LinkPtr> getLinks();

	/**
	 * Create the specified body
	 * @param body label. If the label is negative, does not register the body in the list of bodies of this model.
	 */
	LinkPtr createLink(int label);
	LinkPtr createLink();

	/**
	 * Create a capsule geometry for the body
	 * @param body
	 * @param mass
	 * @param pos
	 * @param direction
	 * @param radius
	 * @param height
	 */
//	dxGeom* createCapsuleGeom(dBodyID body, float mass, const osg::Vec3& pos,
//			int direction, float radius, float height);

	/**
	 * Create a cylinder geometry for the body
	 * @param body
	 * @param mass
	 * @param pos
	 * @param direction
	 * @param radius
	 * @param height
	 */
//	dxGeom* createCylinderGeom(dBodyID body, float mass, const osg::Vec3& pos,
//			int direction, float radius, float height);

	/**
	 * Fix bodies together
	 * @param b1 first body
	 * @param b2 second body
	 * @param axis the axis along which the bodies will be aligned
	 * @param a slider joint
	 */
//	dJointID fixBodies(dBodyID b1, dBodyID b2, const osg::Vec3& axis);

	/**
	 * Set orientation to parent slot with increments of 90 degrees
	 * @param orientation integer between 0 and 3, specifying the amount of
	 * additional 90 degree increments after attaching the part to its parent.
	 */
	bool setOrientationToParentSlot(int orientation);

	/**
	 * Get orientation to parent slot.
	 * @return a number specifying the amount of additional 90 degree increments
	 * after attaching the part to its parent.
	 */
	int getOrientationToParentSlot();

protected:

	/**
	 * Add a body to the model
	 * @param body
	 */
	void addLink(LinkPtr body, int id);

private:

	/**
	 * User-defined identifier of the part
	 */
	const std::string id_;

	/**
	 * Orientation at parent slot: 0-3, where the number stands for
	 * increments of 90 degrees when attaching to the parent part.
	 */
	int orientationToParentSlot_;

	/**
	 * Bodies are now SDF Links
	 */
	std::map<int, LinkPtr> links_;

};

}

#endif /* SDFB_MODEL_H_ */
