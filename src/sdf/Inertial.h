/*
 * Inertial.h
 *
 *  Created on: Feb 23, 2015
 *      Author: elte
 */

#ifndef SDF_INERTIAL_H_
#define SDF_INERTIAL_H_

namespace sdf_builder {

class Inertial : public Element {
	/**
	 * Return XML representation
	 */
	std::string toXML();
public:
	Inertial();
	virtual ~Inertial();


};

} /* namespace sdf_builder */

#endif /* SDF_INERTIAL_H_ */
