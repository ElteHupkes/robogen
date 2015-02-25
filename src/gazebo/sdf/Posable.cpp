/*
 * Posable.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: elte
 */

#include <gazebo/sdf/Posable.h>

namespace sdf_builder {

Posable::Posable(std::string name):
	name_(name),
	pose_(PosePtr(new Pose))
{}
Posable::~Posable() {}

PosePtr Posable::pose() {
	return pose_;
}

const std::string Posable::name() {
	return name_;
}

void Posable::name(std::string nm) {
	name_ = nm;
}

void Posable::setPosition(const Vector3& pos) {
	this->pose_->setPosition(pos);
}

void Posable::setRotation(const Quaternion &rot) {
	this->pose_->setRotation(rot);
}

} /* namespace sdf_builder */
