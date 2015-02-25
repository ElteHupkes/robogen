/**
 * @TODO License
 */
#ifndef SDF_LINK_H_
#define SDF_LINK_H_

#include <gazebo/sdf/Posable.h>
#include <gazebo/sdf/PosableParent.h>
#include <gazebo/sdf/Inertial.h>

#include <boost/shared_ptr.hpp>

namespace sdf_builder {

/**
 * A link represents a collection of body parts
 */
class Link : public Posable, public PosableParent  {
public:
	Link(std::string name);
	virtual ~Link();

	/**
	 * Return XML representation
	 */
	std::string toXML();

	/**
	 * Sets the inertial properties of the link
	 */
	void inertial(InertialPtr inert);

	/**
	 * Makes this link act as a box, by adding a box inertia.
	 *
	 * @param Link mass
	 * @param x size
	 * @param y size
	 * @param z size
	 * @param collision If true, also creates a box collision object
	 * @param visual If true, also creates a box visual object
	 */
	void makeBox(double mass, double x, double y, double z,
			bool collision = true, bool visual = false);

protected:
	/**
	 * Inertial properties of the link
	 */
	InertialPtr inertial_;
};

} /* namespace sdf_builder */

#endif /* SDF_LINK_H_ */
