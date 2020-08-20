/*
 * Thug.h
 *
 *  Created on: 7 αιεμι 2020
 *      Author: Harel
 */

#ifndef THUG_H_
#define THUG_H_
#include "Knight.h"

class Thug: public Agent {
private:

public:
	Thug(string& name, pair<double, double>& location,int health = 15, int speed = 10):
		Agent(health, name, location, speed){}
	void position(pair<double, double>& target, int speed){setPosition(target); setSpeed(speed);}
	void course(double angle, int speed){setCourse(angle); setSpeed(speed);}
	void attack(shared_ptr<Peasant>& peas, set<shared_ptr<Knight>>& knights);
	void setSpeed(int speed){if(speed < 31) Agent::setSpeed(speed);}
	virtual ~Thug(){};
};

#endif /* THUG_H_ */
