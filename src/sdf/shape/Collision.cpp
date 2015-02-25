/*
 * Collision.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: elte
 */

#include <sdf/shape/Collision.h>

namespace sdf_builder {

Collision::Collision(std::string name):
	Shape(name)
{}

Collision::Collision(std::string name, GeometryPtr geom):
	Shape(name, geom)
{}

Collision::~Collision()
{}

std::string Collision::toXML() {
	std::stringstream out;

	out << "<collision name=\"" << name_ << "\">"
			<< geometry_->toXML()
			<< "</collision>";

	return out.str();
}

} /* namespace sdf_builder */
