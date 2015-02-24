/**
 * @TODO License
 */
#include <sdf/Model.h>

namespace sdf_builder {

Model::Model(std::string name):
	Posable(name),
	isStatic_(false)
	{}

Model::~Model() {}

std::string Model::toXML() {
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
