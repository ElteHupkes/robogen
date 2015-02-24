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
	explicit Geometry(double mass = 0);

	virtual ~Geometry();

	/**
	 * @return XML representation
	 */
	double mass() { return mass_; }

	/**
	 * @return XML representation
	 */
	std::string toXML();
protected:
	/**
	 *
	 */
	double mass_;
};

} /* namespace sdf_builder */

#endif /* SDF_GEOMETRY_H_ */
