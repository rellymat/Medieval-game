/*
 * ViewBase.h
 *
 *  Created on: 21 αιεμι 2020
 *      Author: Harel
 */

#ifndef VIEWBASE_H_
#define VIEWBASE_H_
#include <iostream>
#include <string>
#include <sstream>
#include "SimObject.h"
using namespace std;

class ViewBase {
private:
	int size;
	double scale;
	pair<double, double> origin;
	string** world;
	void createMap();
	void addObjectToMap();
	set<shared_ptr<SimObject>> objects;
	bool connected;
public:
	ViewBase();
	void show();
	virtual ~ViewBase();
	void do_default();
	bool attach(){
		if(!connected)
			return connected = true;
		else
			return false;
	}
    void detach(){ connected = false;}
	void setOrigin(const pair<double, double>& origin) {
		this->origin.first = origin.second;
		this->origin.second = origin.first;
		createMap();
	}

	void setScale(double scale) {
		this->scale = scale;
		createMap();
	}

	void setSize(int size) {
		this->size = size;
		createMap();
	}

	void setObjects(const set<shared_ptr<SimObject> >& objects) {
		this->objects = objects;
	}
};

#endif /* VIEWBASE_H_ */
