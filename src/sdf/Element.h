/*
 * Element.h
 *
 *  Created on: Feb 23, 2015
 *      Author: elte
 */

#ifndef SDF_ELEMENT_H_
#define SDF_ELEMENT_H_

// stdlib classes
#include <string>
#include <sstream> // Common to use for toXML

// sdfbuilder
#include <sdf/SdfBuilder.h>

namespace sdf_builder {

class Element {
public:
	Element();
	virtual ~Element();

	/**
	 * Returns the full XML string representation
	 * of this element.
	 */
	virtual std::string toXML() = 0;
};

} /* namespace sdf_builder */

#endif /* SDF_ELEMENT_H_ */
