/**
 * @TODO License
 */
#ifndef SDF_COLLISION_H_
#define SDF_COLLISION_H_

#include "sdf/Pose.h"
#include "sdf/geometry/Geometry.h"

namespace sdf_builder {

/**
 * A link represents a collection of body parts
 */
class Collision : public Element {
	/**
	 * Converts the element to XML
	 */
	std::string toXML();

private:
	/**
	 * The current pose of this link within the
	 * parent model.
	 */
	Pose pose_;

	/**
	 * Geometry of this collision object
	 */
	Geometry geometry_;
};

} /* namespace sdf_builder */

#endif /* SDFB_COLLISION_H_ */
