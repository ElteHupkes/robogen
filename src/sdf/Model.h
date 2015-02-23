/**
 * @TODO License
 */
#ifndef SDF_MODEL_H_
#define SDF_MODEL_H_

// stdlib libraries
#include <string>
#include <vector>

// SDF builder libraries
#include "sdf/Pose.h"

namespace sdf_builder {

/**
 * An SDF model
 */
class Model : public Element  {
	// Needs:
	// - Position
	// - List of links
	// - static flag
public:
	/**
	 * Pose of the model
	 */
	Pose pose_;

	/**
	 *
	 */
	std::string name_;

	/**
	 * Whether or not this model has the static
	 * property in the world.
	 */
	bool isStatic_;
};

} /* namespace sdf */

#endif /* SDF_MODEL_H */
