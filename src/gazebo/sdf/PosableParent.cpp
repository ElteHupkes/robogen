/*
 * TODO license
 */

#include <gazebo/sdf/PosableParent.h>

namespace sdf_builder {

PosableParent::PosableParent() {}

PosableParent::~PosableParent() {}

void PosableParent::addPosable( PosablePtr element ) {
	posables_.push_back(element);
}

const std::vector< PosablePtr > PosableParent::posables() {
	return posables_;
}

} /* namespace sdf_builder */
