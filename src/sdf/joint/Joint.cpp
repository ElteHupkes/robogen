/*
 * Joint.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: elte
 */

#include <sdf/joint/Joint.h>

namespace sdf_builder {

Joint::Joint(std::string name):
	Posable(name)
{}

Joint::~Joint()
{}

} /* namespace sdf_builder */
