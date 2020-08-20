/*
 * Structure.h
 *
 *  Created on: 5 αιεμι 2020
 *      Author: Harel
 */

#ifndef STRUCTURE_H_
#define STRUCTURE_H_
#include "SimObject.h"

class Structure: public SimObject {
private:
	int amount;
public:
	virtual ~Structure(){}
	virtual void update() = 0;
	void deposit(int dep){ amount += dep;}
	Structure(string& name, pair<double,double>& location, int amount) : SimObject(name,location), amount(amount) {}
	int getAmount() const {
		return amount;
	}
	string broadcastCurrecState();
};

#endif /* STRUCTURE_H_ */
