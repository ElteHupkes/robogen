/*
 * Limit.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: elte
 */

#include <gazebo/sdf/joint/axis/Limit.h>

namespace sdf_builder {

Limit::Limit(double lower, double upper):
		lower(lower),
		upper(upper),
		continuous(false)
{
	// TODO replace with delegation when using C++11
	init();
}

Limit::Limit():
	lower(-1e+16),
	upper(1e+16),
	continuous(true)
{
	init();
}

Limit::~Limit()
{}

void Limit::init() {
	effort = -1;
	velocity = -1;
	dissipation = 1;
}

std::string Limit::toXML() {
	std::stringstream out;

	out << "<limit>";

	if (!continuous) {
		out << "<lower>" << nf(lower) << "</lower>"
				<< "<upper>" << nf(upper) << "</upper>";
	}

	out << "<effort>" << nf(effort) << "</effort>";
	out << "<velocity>" << nf(velocity) << "</velocity>";
	out << "dissipation>" << nf(dissipation) << "</dissipation>";
	out << "</limit>" << '\n';

	return out.str();
}

} /* namespace sdf_builder */
