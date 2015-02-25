/*
 * Axis.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: elte
 */

#include <gazebo/sdf/joint/axis/Axis.h>

namespace sdf_builder {

Axis::Axis():
	useParentModelFrame(false),
	tagName("axis"),
	xyz_(Vector3(0, 0, 1))
{}

Axis::~Axis()
{}

const Vector3& Axis::xyz() {
	return xyz_;
}

void Axis::xyz(const Vector3& vec) {
	xyz_.set(vec.x(), vec.y(), vec.z());
}

std::string Axis::toXML() {
	std::stringstream out;

	out << "<" << tagName << ">"
			<< "<xyz>"
			<< nf(xyz_.x()) << ' '
			<< nf(xyz_.y()) << ' '
			<< nf(xyz_.z()) << ' '
			<< "</xyz>"
		<< "<use_parent_model_frame>"
		<< (useParentModelFrame ? "1" : "0")
		<< "</use_parent_model_frame>";

	std::vector< ElementPtr >::iterator it = elements_.begin();
	for (; it != elements_.end(); ++it) {
		out << it->get()->toXML() << '\n';
	}

	if (limit) {
		out << limit->toXML() << '\n';
	}

	out << "</" << tagName << ">";
	return out.str();
}

} /* namespace sdf_builder */
