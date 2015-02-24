/*
 * TODO license
 */

#include <sdf/PosableParent.h>

namespace sdf_builder {

PosableParent::PosableParent() {}

PosableParent::~PosableParent() {}

void PosableParent::addPosable( boost::shared_ptr< Posable > element ) {
	posables_.push_back(element);
}

const std::vector< boost::shared_ptr< Posable > > PosableParent::posables() {
	return posables_;
}

} /* namespace sdf_builder */
