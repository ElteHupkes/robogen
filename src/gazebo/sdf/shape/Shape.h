/*
 * Shape.h
 *
 *  Created on: Feb 25, 2015
 *      Author: elte
 */

#ifndef SDF_SHAPE_SHAPE_H_
#define SDF_SHAPE_SHAPE_H_

#include <gazebo/sdf/Posable.h>
#include <gazebo/sdf/geometry/Geometry.h>

namespace sdf_builder {

/**
 * Shape is used by both visual and collision elements. A shape
 * should have a certain geometry.
 */
class Shape: public Posable {
public:
	/**
	 * Default constructor initializes the shape with
	 * a unit size box.
	 */
	Shape(std::string name);
	Shape(std::string name, GeometryPtr geom);
	virtual ~Shape();

	/**
	 * @return The geometry of this shape
	 */
	const GeometryPtr geometry();

	/**
	 * Sets the geometry
	 */
	void geometry(GeometryPtr geom);

protected:
	/**
	 * The geometry of this shape
	 */
	GeometryPtr geometry_;
};

} /* namespace sdf_builder */

#endif /* SDF_SHAPE_SHAPE_H_ */
