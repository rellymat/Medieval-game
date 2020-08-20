/*
 * Thug.cpp
 *
 *  Created on: 7 αιεμι 2020
 *      Author: Harel
 */

#include "Thug.h"


void Thug::attack(shared_ptr<Peasant>& peas,
		set<shared_ptr<Knight> >& knights) {
	bool attack = true;
	if(distance(peas.get()) <= 1.5){
		if(peas.get()->getHealth() < getHealth()){
			for(auto k : knights){
				if(peas.get()->distance(k.get()) <= 2.5){
					attack = false;
					break;
				}
			}
		}
		peas.get()->setHealth(peas.get()->getHealth() - 1);
		if(attack){
			peas.get()->attacked();
			peas.get()->stop();
			if(getHealth() < 20)
				setHealth(getHealth() + 1);
		} else{
			setHealth(getHealth() - 1);
		}

		stop();
		setLocation(peas.get()->getLocation());
		if(getHealth() == 0)
			setStatus("Dead");
		if(peas.get()->getHealth() == 0)
			peas.get()->setStatus("Dead");
	}
}
