/*
 * SimObject.h
 *
 *  Created on: 4 αιεμι 2020
 *      Author: Harel
 */

#ifndef SIMOBJECT_H_
#define SIMOBJECT_H_
#include <iostream>
#include <sstream>
#include <memory>
#include <cmath>
#include <math.h>
#include <set>
#include <iterator>
using namespace std;

class SimObject {
private:
	string name;
	pair<double, double> location;
public:
	SimObject(string& name, pair<double, double>& location) : name(name), location(location){}
	virtual string& getName() {return name;}
	virtual pair<double,double>& getLocation(){return location;}
	virtual void update() = 0;
	virtual string broadcastCurrecState() = 0;
	virtual ~SimObject() {
	}
	void setLocation(const pair<double, double>& location) {
		this->location = location;
	}

	;
};

#endif /* SIMOBJECT_H_ */
