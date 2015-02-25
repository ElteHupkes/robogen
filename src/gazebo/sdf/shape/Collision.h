/*
 * Collision.h
 *
 *  Created on: Feb 25, 2015
 *      Author: elte
 */

#ifndef SDF_SHAPE_COLLISION_H_
#define SDF_SHAPE_COLLISION_H_

#include <gazebo/sdf/shape/Shape.h>

namespace sdf_builder {

class Collision: public Shape {
public:
	Collision(std::string name);
	Collision(std::string name, GeometryPtr geom);
	virtual ~Collision();

	/**
	 * @return XML representation
	 */
	virtual std::string toXML();
};

} /* namespace sdf_builder */

#endif /* SDF_SHAPE_COLLISION_H_ */
