#ifndef _SDFB_H_
#define _SDFB_H_

// stdlib
#include <cmath>

// boost
#include <boost/shared_ptr.hpp>

// other
#include <osg/PositionAttitudeTransform>

namespace sdf_builder {
	typedef osg::Vec3d Vector3;
	typedef osg::Quat Quaternion;
}

// Define number format function, can change this later
// if simple output doesn't suffice.
#define nf(x) (x)

#endif
