/*
 * @TODO License
 */

#include "sdf/Inertial.h"


namespace sdf_builder {

/**
 * Initialize with identity inertia tensor and
 * unity mass.
 */
Inertial::Inertial():
	mass(1.0),
	ixx(1),
	ixy(0),
	ixz(0),
	iyy(1),
	iyz(0),
	izz(1)
{}

Inertial::~Inertial() {}

/**
 * @return XML representation of the inertial
 */
std::string Inertial::toXML() {
	std::stringstream out;

	out << "<inertial>"
		<< "<mass>" << nf(mass) << "</mass>"
		<< "<inertia>"
			<< "<ixx>" << nf(ixx) << "</ixx>"
			<< "<ixy>" << nf(ixy) << "</ixy>"
			<< "<ixz>" << nf(ixz) << "</ixz>"
			<< "<iyy>" << nf(iyy) << "</iyy>"
			<< "<iyz>" << nf(iyz) << "</iyz>"
			<< "<izz>" << nf(izz) << "</izz>"
		<< "</inertia>";
	"</inertial>";

	return out.str();
}

void Inertial::setBox(double mass, double x, double y, double z) {
	double r = mass/12.;
	ixx = r * (y * y + z * z);
	ixy = 0;
	ixz = 0;
	iyy = r * (x * x + z * z);
	iyz = 0;
	izz = r * (x * x + y * y);
}

void Inertial::setCylinder(double mass, double radius, double height) {
	// TODO Implement
	 // TODO Figure out sensible directions for radius / height, can probably check what ODE does.
}


} /* namespace sdf_builder */
