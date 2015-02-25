/*
 * Axis.h
 *
 *  Created on: Feb 25, 2015
 *      Author: elte
 */

#ifndef GAZEBO_SDF_JOINT_AXIS_H_
#define GAZEBO_SDF_JOINT_AXIS_H_

#include <vector>

#include <gazebo/sdf/Element.h>

namespace sdf_builder {

class Axis: public Element {
public:
	Axis();
	virtual ~Axis();

	/**
	 * Whether to use the parent model frame
	 * for this axis.
	 */
	bool useParentModelFrame;

	/**
	 * The tag name for this axis, so it can
	 * be reused for both "axis1" and "axis2"
	 */
	std::string tagName;

	/**
	 * Limit, if applicable
	 */
	LimitPtr limit;

	/**
	 * @param Element to add
	 */
	void addElement(ElementPtr element);

	/**
	 * @return Direction vector of this axis
	 */
	const Vector3 & xyz();

	/**
	 * @param Direction of the axis
	 */
	void xyz(const Vector3& xyz);

	/**
	 * @return XML representation
	 */
	std::string toXML();

protected:
	/**
	 * The vector of the axis
	 */
	Vector3 xyz_;

	/**
	 * List of other elements that should be
	 * rendered in this axis, generally the
	 * dynamics and limits are imposed here.
	 */
	std::vector< ElementPtr > elements_;
};

} /* namespace sdf_builder */

#endif /* GAZEBO_SDF_JOINT_AXIS_H_ */
