/**
 * TODO License
 */
// stdlib
#include <sstream>

// sdfbuilder
#include <gazebo/sdf/Link.h>
#include <gazebo/sdf/geometry/Box.h>
#include <gazebo/sdf/shape/Collision.h>
#include <gazebo/sdf/shape/Visual.h>

namespace sdf_builder {

Link::Link(std::string nm) :
	Posable(nm),
	inertial_(InertialPtr(new Inertial))
{}

Link::~Link()
{}

void Link::inertial(InertialPtr inert) {
	inertial_ = inert;
}

void Link::makeBox(double mass, double x, double y, double z,
		bool collision, bool visual) {
	// Give our inertial box properties
	inertial_->setBox(mass, x, y, z);

	if (collision) {
		// Create the collision box
		BoxPtr box(new Box(x, y, z));
		CollisionPtr col(new Collision("collision", box));
		this->addPosable(col);
	}

	if (visual) {
		// Create the collision box
		BoxPtr box(new Box(x, y, z));
		VisualPtr vis(new Visual("collision", box));
		this->addPosable(vis);
	}
}

/**
 * @return XML representation of the link
 */
std::string Link::toXML() {
	std::stringstream out;

	out << "<link name=\"" << name_ << "\">";
	out << pose_->toXML() << '\n';
	out << inertial_->toXML() << '\n';

	for (int i = 0, l = posables_.size(); i < l; ++i) {
		out << posables_[i]->toXML() << '\n';
	}

	out << "</link>" << '\n';
	return out.str();
}

} /* namespace sdf_builder */
