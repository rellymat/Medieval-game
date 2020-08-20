/*
 * Peasant.cpp
 *
 *  Created on: 6 αιεμι 2020
 *      Author: Harel
 */

#include "Peasant.h"

string Peasant::broadcastCurrecState() {
	return "Peasant " + Agent::broadcastCurrecState();
}

void Peasant::start_working(shared_ptr<Farm>& farm,
		shared_ptr<Castle>& castle) {
	source = farm;
	dest = castle;
	setDestination(farm);
}

void Peasant::update() {
	if(getStatus().compare("Stopped") != 0){
		Agent::update();
		if(isArrived() && getDestination() == dest){
			deposit(dest);
			stop();
		}
		if(isArrived() && getDestination() == source){
			withdraw(source);
			setDestination(dest);
		}

	}
}
