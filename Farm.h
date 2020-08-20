/*
 * Farm.h
 *
 *  Created on: 5 αιεμι 2020
 *      Author: Harel
 */

#ifndef FARM_H_
#define FARM_H_
#include "Structure.h"

class Farm: public Structure {
private:
	int rate;
public:
	Farm(string& name, pair<double,double>& location, int amount, int rate): Structure(name,location,amount), rate(rate){}
	int withdraw(int amount);
	void update(){Structure::deposit(rate);}
	virtual ~Farm(){};
};

#endif /* FARM_H_ */
