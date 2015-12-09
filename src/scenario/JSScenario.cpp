/*
 * @(#) JSScenario.cpp   1.0   Dec 8, 2015
 *
 * Joshua Auerbach (joshua.auerbach@epfl.ch)
 *
 * The ROBOGEN Framework
 * Copyright © 2012-2015 Joshua Auerbach
 *
 * Laboratory of Intelligent Systems, EPFL
 *
 * This file is part of the ROBOGEN Framework.
 *
 * The ROBOGEN Framework is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License (GPL)
 * as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @(#) $Id$
 */

#ifdef EMSCRIPTEN

#include "scenario/JSScenario.h"
#include "scenario/Environment.h"
#include "Robot.h"

#include <sstream>


namespace robogen {

std::map<std::string, JSScenario*> JSScenario::scenarios;



JSScenario::JSScenario() : Scenario(boost::shared_ptr<RobogenConfig>()),
		curTrial_(0) {
	this->setEnvironment(boost::shared_ptr<Environment>(new Environment()));
}

JSScenario::~JSScenario() {
	std::stringstream ss;
	ss << "console.log(\"" << "destroying jsScenario!" << "\")";
	emscripten_run_script(ss.str().c_str());

}

emscripten::val valFromVec3(osg::Vec3 vec) {
	emscripten::val result(emscripten::val::object());
	result.set("x", vec.x());
	result.set("y", vec.y());
	result.set("z", vec.z());
	return result;
}

emscripten::val valFromQuat(osg::Quat quat) {
	emscripten::val result(emscripten::val::object());
	result.set("x", quat.x());
	result.set("y", quat.y());
	result.set("z", quat.z());
	result.set("w", quat.w());
	return result;
}



emscripten::val JSScenario::getRobotPosition(){
	return valFromVec3(this->getRobot()->getCoreComponent()->getRootPosition());
}

void JSScenario::printRobotPosition() {
	osg::Vec3 pos = this->getRobot()->getCoreComponent()->getRootPosition();
	std::stringstream ss;
	ss << "console.log(\"" << pos[0] << " " <<pos[1] << " " << pos[2] << "\")";
	emscripten_run_script(ss.str().c_str());
}

}

#endif
