/**
 * @TODO License
 */
#ifndef SDF_LINK_H_
#define SDF_LINK_H_

#include "sdf/Pose.h"
#include "sdf/Inertial.h"
#include "sdf/Collision.h"

namespace sdf_builder {

/**
 * A link represents a collection of body parts
 */
class Link : public Element  {
	/**
	 * Return XML representation
	 */
	std::string toXML();

protected:
	/**
	 * The current pose of this link within the
	 * parent model.
	 */
	Pose pose_;

	/**
	 * Inertial properties of the link
	 */
	Inertial inertial_;

	/**
	 * List of collision objects
	 */
	std::vector< Collision > collisions_;
};

} /* namespace sdf_builder */

#endif /* SDF_LINK_H_ */
