/*
 * Joint.h
 *
 *  Created on: Feb 24, 2015
 *      Author: elte
 */

#ifndef SDF_JOINT_H_
#define SDF_JOINT_H_

#include "sdf/Posable.h"

namespace sdf_builder {

class Joint: public Posable {
public:
	Joint(std::string name);
	virtual ~Joint();
};

} /* namespace sdf_builder */

#endif /* SDF_JOINT_H_ */
