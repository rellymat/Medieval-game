/*
 * Structure.cpp
 *
 *  Created on: 5 αιεμι 2020
 *      Author: Harel
 */

#include "Structure.h"

string Structure::broadcastCurrecState() {
	string s = "";
	s += getName() + ", at position (";
	pair<double, double> t = getLocation();
	ostringstream strs;
	strs << t.first;
	s += strs.str() + ", ";
	strs.str(std::string());
	strs << t.second;
	s += strs.str() + "), Inventory: ";
	strs.str(std::string());
	strs << getAmount();
	s += strs.str() + '\n';
	return s;
}
