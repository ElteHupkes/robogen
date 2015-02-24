/**
 * @TODO License
 */
#ifndef SDF_LINK_H_
#define SDF_LINK_H_

#include "sdf/Posable.h"
#include "sdf/PosableParent.h"
#include "sdf/Inertial.h"
#include "sdf/Collision.h"

#include <boost/shared_ptr.hpp>

namespace sdf_builder {

/**
 * A link represents a collection of body parts
 */
class Link : public Posable, public PosableParent  {
public:
	Link(std::string name_);
	virtual ~Link();

	/**
	 * Return XML representation
	 */
	std::string toXML();
protected:
	/**
	 * Inertial properties of the link
	 */
	boost::shared_ptr< Inertial > inertial_;
};

} /* namespace sdf_builder */

#endif /* SDF_LINK_H_ */
