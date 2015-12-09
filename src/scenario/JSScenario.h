/*
 * @(#) JsScenario.h   1.0   Dec 8, 2015
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
#ifndef ROBOGEN_JSSCENARIO_H_
#define ROBOGEN_JSSCENARIO_H_

#ifdef EMSCRIPTEN


#include <emscripten/bind.h>
#include <emscripten.h>

#include <stdio.h>
#include "scenario/Scenario.h"
#include <map>

namespace robogen {



class JSScenario: public Scenario {



public:


	JSScenario();

	/**
	 * Destructor
	 */
	virtual ~JSScenario();


	/**
	 * Methods inherited from {@link #Scenario}
	 */


	emscripten::val getRobotPosition();

	// for now do nothing on any of these except getFitness, which
	// will be pure virtual here
	virtual bool setupSimulation() = 0;
	virtual bool afterSimulationStep() { return true; }
	virtual bool endSimulation() { curTrial_++; return endSimulationJS();}
	virtual bool endSimulationJS() = 0;
	virtual double getFitness() = 0;
	virtual bool remainingTrials() {
		//TODO make do something more useful
		return curTrial_ < 1;
	}
	virtual int getCurTrial() const {
		return curTrial_;
	}

	std::string getId() {
		return id_;
	}

	void setId(std::string id) {
		id_ = id;
		scenarios[id] = this;
	}

	static JSScenario *getScenario(std::string str) {
		if( scenarios.count(str) > 0 )
			return scenarios[str];
		else
			return NULL;
	}

	void printRobotPosition();


	/*std::string getPointerString() {
		  char buff[100];
		  std::sprintf(buff, "%p", (void *) this);
		  std::string r = buff;
		  return r;
	}

	static JSScenario *fromPointerString(char * str) {
		void *p;
		std::sscanf(str, "%p", &p );
		return (JSScenario *) p;
	}*/


private:
	std::string id_;
	unsigned int curTrial_;

	static std::map<std::string, JSScenario*> scenarios;


};

}

#endif


#endif /* ROBOGEN_JSSCENARIO_H_ */
