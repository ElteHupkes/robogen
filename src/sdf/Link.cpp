/**
 * TODO License
 */
// stdlib
#include <sstream>

// sdfbuilder
#include <sdf/Link.h>

namespace sdf_builder {

Link::Link(std::string name) :
	Posable(name),
	inertial_(InertialPtr(new Inertial))
{}

Link::~Link()
{}


/**
 * @return XML representation of the link
 */
std::string Link::toXML() {
	std::stringstream out;

	out << "<link name=\"" << name_ << "\">";

	out << inertial_->toXML() << '\n';

	for (int i = 0, l = posables_.size(); i < l; ++i) {
		out << posables_[i]->toXML() << '\n';
	}

	out << "</link>" << '\n';
	return out.str();
}

} /* namespace sdf_builder */
