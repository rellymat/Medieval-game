/*
 * Agent.cpp
 *
 *  Created on: 5 αιεμι 2020
 *      Author: Harel
 */

#include "Agent.h"

Agent::Agent(int health, string& name, pair<double, double>& location,
		int speed) :
		SimObject(name, location) {
	this->health = health;
	status = "Stopped";
	mo = new MovingObject(location, speed);

}

string Agent::broadcastCurrecState() {
	string s = getName() + " at (";
	pair<double, double> t = getLocation();
	ostringstream strs;
	strs << t.first;
	s += strs.str() + ", ";
	strs.str(std::string());
	strs << t.second;
	s += strs.str() + "), " + status;
	strs.str(std::string());
	if (status.compare("Stopped") != 0 && status.compare("Dead") != 0) {
		if (status.compare("Moving on course ") == 0) {
			strs << mo->getAngle();
			s += strs.str() + " deg";
			strs.str(std::string());
		}
		strs << mo->getSpeed();
		s += ", speed " + strs.str() + " km/h";
	}
	return s + '\n';
}

void Agent::update() {
	if (status.compare("Stopped") == 0)
		return;
	mo->startMoving();
	pair<double, double> loc = mo->getLocation();
	setLocation(loc);
	if (mo->isArrived())
		status = "Stopped";
}

double Agent::distance(Agent* agent) {
	pair<double, double> thug = getLocation();
	pair<double, double> ageLoc = agent->getLocation();
	double res = sqrt(
			pow(thug.first - ageLoc.first, 2)
					+ pow(thug.second - ageLoc.second, 2));
	return res;
}
