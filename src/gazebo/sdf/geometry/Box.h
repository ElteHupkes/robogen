/*
 * Box.h
 *
 *  Created on: Feb 25, 2015
 *      Author: elte
 */

#ifndef SDF_GEOMETRY_BOX_H_
#define SDF_GEOMETRY_BOX_H_

#include <gazebo/sdf/geometry/Geometry.h>

namespace sdf_builder {

class Box: public Geometry {
public:
	explicit Box(double x = 1, double y = 1, double z = 1);
	virtual ~Box();

	/**
	 * @return XML representation
	 */
	std::string toXML();

	// Box size
	double x;
	double y;
	double z;
};

} /* namespace sdf_builder */

#endif /* SDF_GEOMETRY_BOX_H_ */
