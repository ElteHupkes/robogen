/**
 * @TODO License
 */
#include <sstream>
#include <cmath>

#include <sdf/Pose.h>

namespace sdf_builder {

Pose::Pose() {}

Pose::~Pose() {}

/**
 * Sets x / y / z
 */
void Pose::setPosition(Vector3 pos) {
	pos_ = pos;
}

/**
 * Sets the rotation quaternion. This vector
 * should not be of zero length.
 */
void Pose::setRotation(Quaternion rot) {
	double len = rot.length();
	rot_ = rot / len;
}

/**
 * Return rotation as roll / pitch / yaw,
 * kindly taken from Gazebo.
 */
osg::Vec3d Pose::rotationToEuler() {
	  Vector3 vec;

	  double w = rot_.w();
	  double x = rot_.x();
	  double y = rot_.y();
	  double z= rot_.z();

	  double squ;
	  double sqx;
	  double sqy;
	  double sqz;

	  squ = w * w;
	  sqx = x * x;
	  sqy = y * y;
	  sqz = z * z;

	  // Roll
	  vec[0] = atan2(2 * (y*z + w*x), squ - sqx - sqy + sqz);

	  // Pitch
	  double sarg = -2 * (x*z - w * y);
	  vec[1] = sarg <= -1.0 ? -0.5*M_PI : (sarg >= 1.0 ? 0.5*M_PI : asin(sarg));

	  // Yaw
	  vec[2] = atan2(2 * (x*y + w*z), squ + sqx - sqy - sqz);

	  return vec;
}

/**
 * Sets the roll, pitch and yaw based on the given
 * quaternion values. The quaternion should be normalized.
 */

/**
 * Return XML output of this Pose object
 */
std::string Pose::toXML() {
	Vector3 euler = this->rotationToEuler();

	std::stringstream out;
	out << "<pose>"
		<< pos_[0] << " " << pos_[1] << ' ' << pos_[2] << ' '
		<< euler[0] << ' ' << euler[1] << ' ' << euler[2]
		<< "</pose>" << '\n';
	return out.str();
}

} /* namespace sdf_builder */
