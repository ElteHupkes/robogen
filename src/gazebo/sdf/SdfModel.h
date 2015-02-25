/**
 * @TODO License
 */
#ifndef SDF_MODEL_H_
#define SDF_MODEL_H_

// stdlib libraries
#include <string>
#include <vector>

// SDF builder libraries
#include <gazebo/sdf/Posable.h>
#include <gazebo/sdf/PosableParent.h>

namespace sdf_builder {

/**
 * An SDF model
 */
class SdfModel : public Posable, public PosableParent  {
public:
	SdfModel(std::string name);
	virtual ~SdfModel();

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
