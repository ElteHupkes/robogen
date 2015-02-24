/*
 * @TODO License
 */

#ifndef SDF_POSABLE_H_
#define SDF_POSABLE_H_

// sdfbuilder
#include "sdf/SdfBuilder.h"
#include "sdf/Pose.h"
#include "sdf/Element.h"

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
	boost::shared_ptr< Pose > pose();

	/**
	 * @return Name of the posable
	 */
	const std::string name();

	/**
	 * Set the name of the posable
	 */
	void setName(std::string name);
protected:
	/**
	 * Name of the element
	 */
	std::string name_;

	/**
	 * Pose of the element
	 */
	boost::shared_ptr< Pose > pose_;
};

} /* namespace sdf_builder */

#endif /* SDF_POSABLE_H_ */
