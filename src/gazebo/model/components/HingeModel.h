/*
 *
 */
#ifndef SDFB_HINGE_MODEL_H_
#define SDFB_HINGE_MODEL_H_

#include "gazebo/model/Model.h"

namespace sdf_builder {

/**
 * A Hinge is modelled with 4 boxes and a hinge joint
 */
class HingeModel: public Model {

public:

	static const float MASS_SLOT;
	static const float MASS_FRAME;

	static const float SLOT_WIDTH;
	static const float SLOT_THICKNESS;
	static const float CONNNECTION_PART_LENGTH;
	static const float CONNECTION_PART_HEIGHT;
	static const float CONNECTION_PART_THICKNESS;
	static const float CONNECTION_ROTATION_OFFSET;

	static const unsigned int SLOT_A = 0;
	static const unsigned int SLOT_B = 1;

	static const unsigned int B_SLOT_A_ID = 0;
	static const unsigned int B_SLOT_B_ID = 1;
	static const unsigned int B_CONNECTION_A_ID = 2;
	static const unsigned int B_CONNECTION_B_ID = 3;

	HingeModel(std::string id);

	virtual ~HingeModel();

	virtual bool initModel();

	virtual LinkPtr getRoot();

	virtual LinkPtr getSlot(unsigned int i);

	virtual Vector3 getSlotPosition(unsigned int i);

	virtual Vector3 getSlotOrientation(unsigned int i);

	virtual Vector3 getSlotAxis(unsigned int i);

private:

	LinkPtr hingeRoot_;
	LinkPtr hingeTail_;

};

}

#endif /* ROBOGEN_HINGE_MODEL_H_ */
