/*
 * Posable.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: elte
 */

#include "sdf/Posable.h"

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

void Posable::setName(std::string name) {
	name_ = name;
}

} /* namespace sdf_builder */
