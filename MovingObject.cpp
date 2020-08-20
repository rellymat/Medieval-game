/*
 * MovingObject.cpp
 *
 *  Created on: 5 αιεμι 2020
 *      Author: Harel
 */

#include "MovingObject.h"

void MovingObject::startMoving() {
	if(dest)
		move_to_dest();
	if(tgt)
		move_to_target();
	if(agl)
		move_by_angle();
}

void MovingObject::move_to_dest() {
	target = destination.get()->getLocation();
	dest = false;
	tgt = true;
	move_to_target();
}

void MovingObject::move_to_target() {
	if(distance == 0){
		double x = target.first - location.first;
		double y = target.second - location. second;
		distance = sqrt(x*x + y*y)*10;
		angle = atan2(y,x)*180/3.141592653589793;
	}
	distance -= speed;
	if(distance <= 0){
		location = target;
	}
	else
		move_by_angle();
}

void MovingObject::move_by_angle() {
	double dx = cos(angle* 3.141592653589793 / 180.0) * speed/10;
	double dy = sin(angle* 3.141592653589793 / 180.0) * speed/10;
	location.first += dx;
	location.second += dy;
}
