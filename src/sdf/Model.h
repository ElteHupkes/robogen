/**
 * @TODO License
 */
#ifndef SDF_MODEL_H_
#define SDF_MODEL_H_

// stdlib libraries
#include <string>
#include <vector>

// SDF builder libraries
#include "sdf/Posable.h"
#include "sdf/PosableParent.h"

namespace sdf_builder {

/**
 * An SDF model
 */
class Model : public Posable, public PosableParent  {
public:
	Model(const std::string name);
	virtual ~Model();

	/**
	 * Return XML representation
	 */
	std::string toXML();
protected:
	/**
	 * Whether or not this model has the static
	 * property in the world.
	 */
	bool isStatic_;
};

} /* namespace sdf */

#endif /* SDF_MODEL_H */
