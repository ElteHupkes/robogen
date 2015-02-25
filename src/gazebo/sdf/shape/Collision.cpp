/*
 * Collision.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: elte
 */

#include <gazebo/sdf/shape/Collision.h>

namespace sdf_builder {

Collision::Collision(std::string nm):
	Shape(nm)
{}

Collision::Collision(std::string nm, GeometryPtr geom):
	Shape(nm, geom)
{}

Collision::~Collision()
{}

std::string Collision::toXML() {
	std::stringstream out;

	out << "<collision name=\"" << name_ << "\">"
			<< pose_->toXML()
			<< geometry_->toXML()
			<< "</collision>";

	return out.str();
}

} /* namespace sdf_builder */
