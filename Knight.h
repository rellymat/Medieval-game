/*
 * Knight.h
 *
 *  Created on: 6 αιεμι 2020
 *      Author: Harel
 */

#ifndef KNIGHT_H_
#define KNIGHT_H_
#include "Peasant.h"

class Knight: public Agent {
private:

public:
	Knight(string& name, pair<double, double>& location,int health = 5, int speed = 10):
		Agent(health, name, location, speed){};
	virtual ~Knight(){};
};

#endif /* KNIGHT_H_ */
