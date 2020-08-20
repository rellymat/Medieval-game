/*
 * Model.cpp
 *
 *  Created on: 7 αιεμι 2020
 *      Author: Harel
 */

#include "Model.h"
Model* Model::instance = nullptr;

void Model::createCastles(const char* file) {
	ifstream f;
	string name, line, pointX, pointY;
	int  amount;
	f.open(file);
	while(getline(f, line)){
		stringstream ss(line);
		ss >> name >> pointX >> pointY >>  amount;
		pair<double,double> location(stod(pointX.substr(1,pointX.size() -2)), stod(pointY.substr(0,pointY.size() -2)));
		name = name.substr(0, name.size() -1);
		shared_ptr<Castle> c(new Castle(name, location, amount));
		all_objects.insert(c);
		structures.insert(c);
		castles.insert(c);
	}
	f.close();
}

void Model::createFarms(const char* file) {
	ifstream f;
		string name, line, pointX, pointY, null;
		int  amount, rate;
		f.open(file);
		while(getline(f, line)){
			stringstream ss(line);
			ss >> name >> pointX >> pointY >>  amount >> null >> rate;
			pair<double,double> location(stod(pointX.substr(1,pointX.size() -2)), stod(pointY.substr(0,pointY.size() -2)));
			name = name.substr(0, name.size() -1);
			shared_ptr<Farm> fa(new Farm(name, location, amount, rate));
			all_objects.insert(fa);
			structures.insert(fa);
			farms.insert(fa);
		}
		f.close();
}

void Model::createStructure(int argc, char* argv[]) {
	if(argc != 3)
		throw exception();
	createCastles(argv[1]);
	createFarms(argv[2]);
}

Model* Model::getInstance() {
	if(instance == nullptr)
		instance = new Model();
	return instance;
}

void Model::print() {
	for(auto so : all_objects)
		cout << so.get()->broadcastCurrecState();
}

void Model::addKnight(shared_ptr<Knight>& agent, const string& type) {
	all_objects.insert(agent);
	agents.insert(agent);
	knights.insert(agent);
}


void Model::addThug(shared_ptr<Thug>& agent, const string& type) {
	all_objects.insert(agent);
	agents.insert(agent);
	thugs.insert(agent);
}

void Model::addPeasant(shared_ptr<Peasant>& agent, const string& type) {
	all_objects.insert(agent);
	agents.insert(agent);
	peasants.insert(agent);
}
