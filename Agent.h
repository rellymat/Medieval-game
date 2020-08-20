/*
 * Agent.h
 *
 *  Created on: 5 αιεμι 2020
 *      Author: Harel
 */

#ifndef AGENT_H_
#define AGENT_H_
#include <string>
#include "SimObject.h"
#include "Farm.h"
#include "Castle.h"
#include "MovingObject.h"

class Agent: public SimObject{
private:
	int health;
	MovingObject* mo;
	string status;
public:
	Agent(int health, string& name, pair<double, double>& location, int speed);
	void stop(){status = "Stopped";}
	virtual void setDestination(shared_ptr<Structure> dest){ mo->setDestination(dest);
									 status = "Moving to " + dest.get()->getName();}
	virtual void setCourse(double angle){mo->setAngle(90-angle);
								 status = "Moving on course "; }
	virtual void setPosition(pair<double,double> loc){mo->setTarget(loc);
												status = "Moving to ";}
	virtual string broadcastCurrecState();
	virtual void update();
	virtual void setSpeed(int speed){mo->setSpeed(speed);}
	bool isArrived(){ return mo->isArrived();}
	virtual ~Agent(){delete mo;}
	double distance(Agent* agent);
	void setLocation(pair<double, double>& loc){mo->setLocation(loc); SimObject::setLocation(loc);}
	int getHealth() const {
		return health;
	}

	void setHealth(int health) {
		this->health = health;
	}

	const string& getStatus() const {
		return status;
	}

	void setStatus(const string& status) {
		this->status = status;
	}

	shared_ptr<Structure> getDestination() { return mo->getDestination();}
};

#endif /* AGENT_H_ */
