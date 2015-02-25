#ifndef _SDFB_TYPES_H_
#define _SDFB_TYPES_H_

// stdlib
#include <cmath>

// boost
#include <boost/shared_ptr.hpp>

// other
#include <osg/PositionAttitudeTransform>

namespace sdf_builder {

// Forward declarations
class SdfModel;
class Link;
class Shape;
class Geometry;
class Pose;
class Posable;
class Inertial;
class Box;
class Collision;
class Visual;
class Element;
class Axis;
class Limit;

// Typedefs
typedef osg::Vec3d Vector3;
typedef osg::Quat Quaternion;
typedef boost::shared_ptr< SdfModel > SdfModelPtr;
typedef boost::shared_ptr< Link > LinkPtr;
typedef boost::shared_ptr< Shape > ShapePtr;
typedef boost::shared_ptr< Geometry > GeometryPtr;
typedef boost::shared_ptr< Pose > PosePtr;
typedef boost::shared_ptr< Posable > PosablePtr;
typedef boost::shared_ptr< Inertial > InertialPtr;
typedef boost::shared_ptr< Box > BoxPtr;
typedef boost::shared_ptr< Collision > CollisionPtr;
typedef boost::shared_ptr< Visual > VisualPtr;
typedef boost::shared_ptr< Element > ElementPtr;
typedef boost::shared_ptr< Axis > AxisPtr;
typedef boost::shared_ptr< Axis > LimitPtr;

}

#endif
