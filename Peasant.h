/*
 * Peasant.h
 *
 *  Created on: 6 αιεμι 2020
 *      Author: Harel
 */

#ifndef PEASANT_H_
#define PEASANT_H_
#include "Agent.h"


class Peasant: public Agent {
private:
	int carrier;
	shared_ptr<Farm> source;
	shared_ptr<Castle> dest;
public:
	Peasant(string& name , pair<double, double>& location, int health = 10, int speed = 5):
			Agent(health, name, location, speed){carrier = 0;}
	void start_working(shared_ptr<Farm>& farm, shared_ptr<Castle>& castle);
	string broadcastCurrecState();
	void withdraw(shared_ptr<Farm>& farm) {carrier = farm.get()->withdraw(5); setDestination(farm);}
	void deposit(shared_ptr<Castle>& castle){castle.get()->deposit(carrier); carrier = 0;}
	void attacked(){carrier = 0;}
	virtual ~Peasant() {
	}
	int getCarrier() const {
		return carrier;
	}
	void update();
};

#endif /* PEASANT_H_ */
