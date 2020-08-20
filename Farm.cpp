/*
 * Farm.cpp
 *
 *  Created on: 5 αιεμι 2020
 *      Author: Harel
 */

#include "Farm.h"

int Farm::withdraw(int amount) {
	if(getAmount() < amount)
		amount = getAmount();
	Structure::deposit(-amount);
	return amount;
}
