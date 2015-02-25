/*
 * Visual.h
 *
 *  Created on: Feb 25, 2015
 *      Author: elte
 */

#ifndef GAZEBO_SDF_SHAPE_VISUAL_H_
#define GAZEBO_SDF_SHAPE_VISUAL_H_

#include <gazebo/sdf/shape/Shape.h>

namespace sdf_builder {

class Visual: public Shape {
public:
	explicit Visual(std::string name);
	Visual(std::string name, GeometryPtr geom);
	virtual ~Visual();

	/**
	 * @return XML representation
	 */
	virtual std::string toXML();
};

} /* namespace sdf_builder */

#endif /* GAZEBO_SDF_SHAPE_VISUAL_H_ */
