/*
 *
 */
#include <gazebo/model/Model.h>

#include <stdexcept>
#include <sstream>

#include <boost/lexical_cast.hpp>

namespace sdf_builder {

Model::Model(std::string id) :
		id_(id) {
}

Model::~Model() {

}

const std::string &Model::getId(){
	return id_;
}

Vector3 Model::getRootPosition() {
	return this->getPosition(this->getRoot());
}

Quaternion Model::getRootAttitude() {
	return this->getAttitude(this->getRoot());
}

void Model::setRootPosition(const Vector3& pos) {

	osg::Vec3 curPosition = this->getRootPosition();
	osg::Vec3 translation = pos - curPosition;

	std::map<int, LinkPtr>::iterator it = this->links_.begin();
	for (; it != this->links_.end(); ++it) {
		Vector3 curBodyPos = this->getPosition(it->second);
		curBodyPos += translation;
		it->second->pose()->setPosition(curBodyPos);
	}
}

void Model::translateRootPosition(const Vector3& translation) {

	Vector3 newPosition = this->getRootPosition() + translation;
	this->setRootPosition(newPosition);

}

void Model::setRootAttitude(const Quaternion& quat) {

	Vector3 rootPosition = this->getRootPosition();

	std::map<int, LinkPtr>::iterator it = this->links_.begin();
	for (; it != this->links_.end(); ++it) {
		Vector3 curPosition = this->getPosition(it->second);
		Vector3 relPosition = curPosition - rootPosition;

		// Rotate relPosition
		Vector3 newPosition = quat * relPosition;
		it->second->setPosition(newPosition);

		Quaternion curBodyAttitude = this->getAttitude(it->second);
		curBodyAttitude *= quat;
		it->second->setRotation(curBodyAttitude);
	}

	this->setRootPosition(rootPosition);

}

Vector3 Model::getPosition(LinkPtr link) {
	return link->pose()->position();
}

Quaternion Model::getAttitude(LinkPtr link) {
	return link->pose()->rotation();
}

Vector3 Model::getBodyPosition(int id) {
	return this->getPosition(this->getLink(id));
}

Quaternion Model::getBodyAttitude(int id) {
	return this->getAttitude(this->getLink(id));
}

LinkPtr Model::getLink(int id) {
	std::map<int, LinkPtr>::iterator it = this->links_.find(id);
	if (it == this->links_.end()) {
		std::cout
				<< "[Model] Error: The specified body does not exists in this model"
				<< std::endl;
		assert(it != this->links_.end());

		// Return empty link pointer
		return LinkPtr();
	}
	return links_[id];
}

std::vector<LinkPtr> Model::getLinks() {

	std::vector<LinkPtr> bodies;
	std::map<int, LinkPtr>::iterator it = this->links_.begin();
	for (; it != this->links_.end(); ++it) {
		bodies.push_back(it->second);
	}
	return bodies;

}

void Model::addLink(LinkPtr body, int id) {
	this->links_.insert(std::pair<int, LinkPtr>(id, body));
}

LinkPtr Model::createLink(int label) {
	LinkPtr b(new Link("link_"+id_+boost::lexical_cast<std::string>(label)));
	if (label >= 0) {
		this->addLink(b, label);
	}
	return b;
}

LinkPtr Model::createLink() {
	return this->createLink(-1);
}

//PosablePtr Model::createBoxGeom(LinkPtr link, float mass,
//		float lengthX, float lengthY, float lengthZ) {
//	dMass massOde;
//	dMassSetBoxTotal(&massOde, mass, lengthX, lengthY, lengthZ);
//	dBodySetMass(body, &massOde);
//	dxGeom* g = dCreateBox(this->getCollisionSpace(), lengthX, lengthY,
//			lengthZ);
//	dBodySetPosition(body, pos.x(), pos.y(), pos.z());
//	dGeomSetPosition(g, pos.x(), pos.y(), pos.z());
//	dGeomSetBody(g, body);
//	return g;
//
//}

//dxGeom* Model::createCylinderGeom(dBodyID body, float mass,
//		const osg::Vec3& pos, int direction, float radius, float height) {
//
//	dMass massOde;
//	dMassSetCylinderTotal(&massOde, mass, direction, radius, height);
//	dBodySetMass(body, &massOde);
//	dxGeom* g = dCreateCylinder(this->getCollisionSpace(), radius, height);
//	dBodySetPosition(body, pos.x(), pos.y(), pos.z());
//	dGeomSetPosition(g, pos.x(), pos.y(), pos.z());
//
//	if (direction == 1) {
//
//		osg::Quat rotateCylinder;
//		rotateCylinder.makeRotate(osg::inDegrees(90.0), osg::Vec3(0, 1, 0));
//		dQuaternion quatOde;
//		quatOde[0] = rotateCylinder.w();
//		quatOde[1] = rotateCylinder.x();
//		quatOde[2] = rotateCylinder.y();
//		quatOde[3] = rotateCylinder.z();
//		dBodySetQuaternion(body, quatOde);
//
//	} else if (direction == 2) {
//
//		osg::Quat rotateCylinder;
//		rotateCylinder.makeRotate(osg::inDegrees(90.0), osg::Vec3(1, 0, 0));
//		dQuaternion quatOde;
//		quatOde[0] = rotateCylinder.w();
//		quatOde[1] = rotateCylinder.x();
//		quatOde[2] = rotateCylinder.y();
//		quatOde[3] = rotateCylinder.z();
//		dBodySetQuaternion(body, quatOde);
//
//	}
//
//	dGeomSetBody(g, body);
//
//	return g;
//
//}

//dxGeom* Model::createCapsuleGeom(dBodyID body, float mass, const osg::Vec3& pos,
//		int direction, float radius, float height) {
//
//	dMass massOde;
//	dMassSetCapsuleTotal(&massOde, mass, direction, radius, height);
//	dBodySetMass(body, &massOde);
//	dxGeom* g = dCreateCapsule(this->getCollisionSpace(), radius, height);
//	dBodySetPosition(body, pos.x(), pos.y(), pos.z());
//	dGeomSetPosition(g, pos.x(), pos.y(), pos.z());
//
//	if (direction == 1) {
//
//		osg::Quat rotateCapsule;
//		rotateCapsule.makeRotate(osg::inDegrees(90.0), osg::Vec3(0, 1, 0));
//		dQuaternion quatOde;
//		quatOde[0] = rotateCapsule.w();
//		quatOde[1] = rotateCapsule.x();
//		quatOde[2] = rotateCapsule.y();
//		quatOde[3] = rotateCapsule.z();
//		dBodySetQuaternion(body, quatOde);
//
//	} else if (direction == 2) {
//
//		osg::Quat rotateCapsule;
//		rotateCapsule.makeRotate(osg::inDegrees(90.0), osg::Vec3(1, 0, 0));
//		dQuaternion quatOde;
//		quatOde[0] = rotateCapsule.w();
//		quatOde[1] = rotateCapsule.x();
//		quatOde[2] = rotateCapsule.y();
//		quatOde[3] = rotateCapsule.z();
//		dBodySetQuaternion(body, quatOde);
//
//	}
//
//	dGeomSetBody(g, body);
//
//	return g;
//
//}

//dJointID Model::fixBodies(dBodyID b1, dBodyID b2, const osg::Vec3& /*axis*/) {
//	dJointID joint = dJointCreateFixed(this->getPhysicsWorld(), 0);
//	dJointAttach(joint, b1, b2);
//	dJointSetFixed(joint);
//	return joint;
//
//}

bool Model::setOrientationToParentSlot(int orientation){
	if (orientation < 0 || orientation > 3){
		std::cout << "Specified orientation to parent slot is not"\
				" between 0 and 3." << std::endl;
		return false;
	}
	this->orientationToParentSlot_ = orientation;
	return true;
}

int Model::getOrientationToParentSlot(){
	return this->orientationToParentSlot_;
}

}
