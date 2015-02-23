/**
 * @TODO License
 */
#ifndef SDF_POSE_H_
#define SDF_POSE_H_

namespace sdf_builder {

/**
 * A pose, used all over
 */
class Pose : public Element  {
public:
	double x() { return x_; }
	double y() { return y_; }
	double z() { return z_; }
	double roll() { return roll_; }
	double pitch() { return pitch_; }
	double yaw() { return yaw_; }

	/**
	 * Sets the roll, pitch and yaw based on the given
	 * quaternion values.
	 */
	void setFromQuaternion(double w, double x, double y, double z);

	/**
	 * Converts to XML
	 */
	std::string toXML();

protected:
	double x_ = 0;
	double y_ = 0;
	double z_ = 0;

	double roll_ = 0;
	double pitch_ = 0;
	double yaw_ = 0;
};

} /* namespace sdf_builder */

#endif /* SDF_POSE_H_ */
