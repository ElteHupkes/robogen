#ifndef _SDFB_H_
#define _SDFB_H_

// stdlib
#include <cmath>

// boost
#include <boost/shared_ptr.hpp>

// other
#include <osg/PositionAttitudeTransform>

namespace sdf_builder {

// Forward declarations
class Model;
class Link;
class Shape;
class Geometry;
class Pose;
class Posable;
class Inertial;

// Typedefs
typedef osg::Vec3d Vector3;
typedef osg::Quat Quaternion;
typedef boost::shared_ptr< Model > ModelPtr;
typedef boost::shared_ptr< Link > LinkPtr;
typedef boost::shared_ptr< Shape > ShapePtr;
typedef boost::shared_ptr< Geometry > GeometryPtr;
typedef boost::shared_ptr< Pose > PosePtr;
typedef boost::shared_ptr< Posable > PosablePtr;
typedef boost::shared_ptr< Inertial > InertialPtr;

}

// Define number format function, can change this later
// if simple output doesn't suffice.
#define nf(x) (x)

#endif
