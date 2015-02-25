/*
 * @TODO License
 */

#ifndef SDF_POSABLE_H_
#define SDF_POSABLE_H_

// sdfbuilder
#include <gazebo/sdf/Pose.h>
#include <gazebo/sdf/Element.h>

namespace sdf_builder {

/**
 * A class for posable elements with a name
 */
class Posable : public Element {
public:
	Posable(std::string name);
	virtual ~Posable();

	/**
	 * @return Shared pointer to the Posable's pose
	 */
	PosePtr pose();

	/**
	 * @return Name of the posable
	 */
	const std::string name();

	/**
	 * Set the name of the posable
	 */
	void name(std::string name);

	/**
	 * Sets this link's x/y/z position. Changes the link's
	 * pose object.
	 *
	 * @param 3D position
	 */
	void setPosition(const Vector3& pos);

	/**
	 * Sets this link's rotation using a quaternion. Changes the
	 * link's pose object.
	 *
	 * @param Orientation quaternion
	 */
	void setRotation(const Quaternion& rot);

protected:
	/**
	 * Name of the element
	 */
	std::string name_;

	/**
	 * Pose of the element
	 */
	PosePtr pose_;
};

} /* namespace sdf_builder */

#endif /* SDF_POSABLE_H_ */
