/*
 * FixedJoint.h
 *
 *  Created on: Feb 25, 2015
 *      Author: elte
 */

#ifndef GAZEBO_SDF_JOINT_REVOLUTEJOINT_H_
#define GAZEBO_SDF_JOINT_REVOLUTEJOINT_H_

#include <gazebo/sdf/joint/Joint.h>

namespace sdf_builder {

class RevoluteJoint: public Joint {
public:
	explicit RevoluteJoint(std::string name);
	RevoluteJoint(std::string name, LinkPtr parent, LinkPtr child);
	RevoluteJoint(LinkPtr parent, LinkPtr child);
	virtual ~RevoluteJoint();

	/**
	 * @return XML representation
	 */
	virtual std::string toXML();
};

} /* namespace sdf_builder */

#endif /* GAZEBO_SDF_JOINT_REVOLUTEJOINT_H_ */
