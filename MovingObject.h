/*
 * MovingObject.h
 *
 *  Created on: 5 αιεμι 2020
 *      Author: Harel
 */

#ifndef MOVINGOBJECT_H_
#define MOVINGOBJECT_H_
#include <iostream>
#include "Structure.h"
using namespace std;

class MovingObject {
private:
	shared_ptr<Structure> destination;
	pair<double, double> target, location;
	int speed;
	bool dest, tgt, agl;
	double angle, distance;
	void move_to_dest();
	void move_to_target();
	void move_by_angle();
public:
	MovingObject(pair<double,double> loc, int speed): location(loc), speed(speed){ // @suppress("Class members should be properly initialized")
		dest = tgt = agl = false; distance = angle = 0;
	}
	void startMoving();
	virtual ~MovingObject(){}

	const pair<double, double>& getLocation() const {
		return location;
	}

	void setLocation(const pair<double, double>& location) {
		this->location = location;
	}

	int getSpeed() const {
		return speed;
	}

	void setSpeed(int speed) {
		this->speed = speed;
	}

	double getAngle() const {
		return angle;
	}

	void setAngle(double angle) {
		dest = tgt = false;
		agl = true;
		distance = 0;
		this->angle = angle;
	}

	const shared_ptr<Structure>& getDestination() const {
		return destination;
	}

	void setDestination(const shared_ptr<Structure>& destination) {
		agl = tgt = false;
		dest = true;
		distance = 0;
		this->destination = destination;
	}

	const pair<double, double>& getTarget() const {
		return target;
	}

	void setTarget(const pair<double, double>& target) {
		dest = agl = false;
		tgt = true;
		distance = 0;
		this->target = target;
	}

	bool isArrived(){
		return location == target;
	}
};

#endif /* MOVINGOBJECT_H_ */
