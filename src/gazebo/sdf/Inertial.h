/*
 * @TODO License
 */

#ifndef SDF_INERTIAL_H_
#define SDF_INERTIAL_H_

#include <gazebo/sdf/Element.h>

namespace sdf_builder {

class Inertial : public Element {
public:
	Inertial();
	virtual ~Inertial();

	/**
	 * Sets box inertia
	 */
	void setBox(double mass, double x, double y, double z);

	/**
	 * Set inertia for a cylinder.
	 */
	void setCylinder(double mass, double radius, double height);

	/**
	 * Return XML representation
	 */
	std::string toXML();

	double mass;
	double ixx;
	double ixy;
	double ixz;
	double iyy;
	double iyz;
	double izz;
};

} /* namespace sdf_builder */

#endif /* SDF_INERTIAL_H_ */
