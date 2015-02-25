/*
 * Visual.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: elte
 */

#include <gazebo/sdf/shape/Visual.h>

namespace sdf_builder {

Visual::Visual(std::string nm):
	Shape(nm)
{}

Visual::Visual(std::string nm, GeometryPtr geom):
	Shape(nm, geom)
{}

Visual::~Visual()
{}

std::string Visual::toXML() {
	std::stringstream out;

	out << "<visual name=\"" << name_ << "\">"
			<< pose_->toXML()
			<< geometry_->toXML()
			<< "</visual>";

	return out.str();
}

} /* namespace sdf_builder */
