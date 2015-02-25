/**
 * @TODO License
 */
#include <gazebo/sdf/SdfModel.h>

namespace sdf_builder {

SdfModel::SdfModel(std::string name):
	Posable(name),
	isStatic_(false)
	{}

SdfModel::~SdfModel() {}

std::string SdfModel::toXML() {
	std::stringstream out;

	out << "<model name=\"" << name_ << "\">"
			<< pose_->toXML();

	for (int i = 0, l = posables_.size(); i < l; ++i) {
		out << posables_[i]->toXML() << '\n';
	}

	out << "</model>" << '\n';
	return out.str();
}

} /* namespace sdf_builder */
