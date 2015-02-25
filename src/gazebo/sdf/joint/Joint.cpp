/*
 * Joint.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: elte
 */

#include <gazebo/sdf/joint/Joint.h>
#include <gazebo/sdf/joint/axis/Axis.h>

namespace sdf_builder {

Joint::Joint(std::string nm):
	Posable(nm)
{}

Joint::Joint(std::string nm, LinkPtr parent, LinkPtr child):
	Posable(nm),
	parent(parent),
	child(child),
	axis(AxisPtr(new Axis))
{}

Joint::~Joint()
{}

} /* namespace sdf_builder */
