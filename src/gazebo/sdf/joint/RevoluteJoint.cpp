/*
 * FixedJoint.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: elte
 */

#include <gazebo/sdf/joint/RevoluteJoint.h>

namespace sdf_builder {

RevoluteJoint::RevoluteJoint(std::string name):
	Joint(name)
{}

RevoluteJoint::RevoluteJoint(LinkPtr parent, LinkPtr child):
	Joint(parent, child)
{}

RevoluteJoint::RevoluteJoint(std::string name, LinkPtr parent, LinkPtr child):
	Joint(name, parent, child)
{}

RevoluteJoint::~RevoluteJoint()
{}

std::string RevoluteJoint::toXML() {
	std::stringstream out;

	if (!parent || !child) {
		std::cerr << "Joint " << name_ <<
				" is missing parent or child links, skipping." << std::endl;
		return "";
	}

	out << "<joint type=\"revolute\" name=\"" << name_ << "\">"
			<< pose_->toXML()
			<< "<parent>" << parent->name() << "</parent>" << '\n'
			<< "<child>" << child->name() << "</child>" << '\n'
			<< axis->toXML() << '\n'
		<< "</joint>";

	return out.str();
}

} /* namespace sdf_builder */
