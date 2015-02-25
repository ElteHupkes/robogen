/*
 * TODO License
 */
#include "gazebo/model/components/perceptive/CoreComponentModel.h"

namespace sdf_builder {

// mass of just the brick
const float CoreComponentModel::BRICK_MASS = inGrams(14.9);
// mass of brick with electronics (including battery)
const float CoreComponentModel::CORE_MASS = inGrams(55.4);
const float CoreComponentModel::WIDTH = inMm(46.5);


CoreComponentModel::CoreComponentModel(std::string id, bool hasSensors) :
		PerceptiveComponent(id), hasSensors_(hasSensors) {

	if (hasSensors) {
//		sensor_.reset(new ImuSensor());
	}

}

CoreComponentModel::~CoreComponentModel() {

}

bool CoreComponentModel::initModel() {


	coreComponent_ = this->createLink(B_CORE_COMPONENT_ID);
	double mass = hasSensors_ ? CORE_MASS : BRICK_MASS;

	// Give box geometry
	coreComponent_->makeBox(mass, WIDTH, WIDTH, WIDTH);

	// Already positioned at origin
	return true;
}

LinkPtr CoreComponentModel::getRoot() {
	return coreComponent_;
}

LinkPtr CoreComponentModel::getSlot(unsigned int /*i*/) {
	return coreComponent_;
}

Vector3 CoreComponentModel::getSlotPosition(unsigned int i) {

	if (i > 5) {
		std::cout << "[CoreComponentModel] Invalid slot: " << i << std::endl;
		assert(i <= 5);
	}

	Vector3 curPos = this->getRootPosition();
	Vector3 slotAxis = this->getSlotAxis(i) * WIDTH / 2;
	curPos = curPos + slotAxis;

	return curPos;

}

Vector3 CoreComponentModel::getSlotAxis(unsigned int i) {

	if (i > 5) {
		std::cout << "[CoreComponentModel] Invalid slot: " << i << std::endl;
		assert(i <= 5);
	}

	Quaternion quat = this->getRootAttitude();
	Vector3 axis;

	if (i == LEFT_FACE_SLOT) {

		// Left face
		axis.set(-1, 0, 0);

	} else if (i == RIGHT_FACE_SLOT) {

		// Right face
		axis.set(1, 0, 0);

	} else if (i == TOP_FACE_SLOT) {

		// Top face
		axis.set(0, 0, 1);

	} else if (i == BOTTOM_FACE_SLOT) {

		// Bottom face
		axis.set(0, 0, -1);

	} else if (i == FRONT_FACE_SLOT) {

		// Front face
		axis.set(0, -1, 0);

	} else if (i == BACK_FACE_SLOT) {

		// Back face
		axis.set(0, 1, 0);

	}

	return quat * axis;

}

Vector3 CoreComponentModel::getSlotOrientation(unsigned int i) {

	if (i > 5) {
		std::cout << "[CoreComponentModel] Invalid slot: " << i << std::endl;
		assert(i <= 5);
	}

	Quaternion quat = this->getRootAttitude();
	Vector3 tangent;

	if (i == LEFT_FACE_SLOT) {

		// Left face
		tangent.set(0, 1, 0);

	} else if (i == RIGHT_FACE_SLOT) {

		// Right face
		tangent.set(0, 1, 0);

	} else if (i == TOP_FACE_SLOT) {

		// Top face
		tangent.set(1, 0, 0);

	} else if (i == BOTTOM_FACE_SLOT) {

		// Bottom face
		tangent.set(1, 0, 0);

	} else if (i == FRONT_FACE_SLOT) {

		// Front face
		tangent.set(0, 0, 1);

	} else if (i == BACK_FACE_SLOT) {

		// Back face
		tangent.set(0, 0, 1);

	}

	return quat * tangent;

}

//void CoreComponentModel::getSensors(
//		std::vector<boost::shared_ptr<Sensor> >& sensors) {
//	if (sensor_ != NULL) {
//		sensor_->getSensors(sensors);
//	}
//}
//
//void CoreComponentModel::updateSensors(boost::shared_ptr<Environment>& env) {
//	if (sensor_ != NULL) {
//		sensor_->update(this->getRootPosition(), this->getRootAttitude(),
//				env->getTimeElapsed());
//	}
//}

}
