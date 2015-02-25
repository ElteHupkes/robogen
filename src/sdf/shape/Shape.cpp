/*
 * Shape.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: elte
 */

#include <sdf/shape/Shape.h>
#include <sdf/geometry/Box.h>

namespace sdf_builder {

Shape::Shape(std::string name, GeometryPtr geom):
	Posable(name),
	geometry_(geom)
{}

Shape::Shape(std::string name):
	Shape(name, GeometryPtr(new Box))
{}

Shape::~Shape() {}

const GeometryPtr Shape::geometry() {
	return geometry_;
}

void Shape::geometry(GeometryPtr geom) {
	geometry_ = geom;
}

} /* namespace sdf_builder */
