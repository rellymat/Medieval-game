/*
 * Castle.h
 *
 *  Created on: 5 αιεμι 2020
 *      Author: Harel
 */

#ifndef CASTLE_H_
#define CASTLE_H_
#include "Structure.h"

class Castle: public Structure {
public:
	Castle(string& name, pair<double,double>& location, int amount): Structure(name,location,amount){}
	void update(){}
	virtual ~Castle(){}
};

#endif /* CASTLE_H_ */
