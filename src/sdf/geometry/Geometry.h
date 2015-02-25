/*
 * Geometry.h
 *
 *  Created on: Feb 23, 2015
 *      Author: elte
 */

#ifndef SDF_GEOMETRY_H_
#define SDF_GEOMETRY_H_

#include <sdf/Element.h>

namespace sdf_builder {

class Geometry: public Element {
public:
	Geometry();
	virtual ~Geometry();

	/**
	 * @return XML representation
	 */
	virtual std::string toXML() = 0;
};

} /* namespace sdf_builder */

#endif /* SDF_GEOMETRY_H_ */
