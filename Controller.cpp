/*
 * Controller.cpp
 *
 *  Created on: 21 αιεμι 2020
 *      Author: Harel
 */

#include "Controller.h"


void Controller::createAgent(string& name, const string& type,
		pair<double, double>& location) {
	if(type.compare("Peasant") == 0){
		shared_ptr<Peasant> p(new Peasant(name, location));
		m.get()->addPeasant(p, type);
	} else {
		shared_ptr<Thug> t(new Thug(name, location));
		m.get()->addThug(t, type);
	}
}

Controller::Controller(Model* m, ViewBase* vb) : m(m), v(vb) {
	this->m.get()->attach(v);
	v.get()->attach();
}

void Controller::createKnight(string& name, const string& type,
		const string& place) {
	set<shared_ptr<SimObject>> s = m.get()->getAllObject();
	shared_ptr<SimObject> pl;
	bool flag = false;
	for(auto so : s){
		if(so.get()->getName().compare(place) == 0){
			pl = so;
			flag = true;
			break;
		}
	}

	if(flag){
		pair<double, double> lo = pl.get()->getLocation();
		shared_ptr<Knight> k(new Knight(name, lo));
		m.get()->addKnight(k, type);
		return;
	}
	throw exception();
}

bool Controller::orderView(string& order) {
	int size;
	double num1, num2;
	if(order.compare("default") == 0){
		do_default();
		return true;
	} else if(order.compare("size") == 0){
		cin >> size;
		if(cin.good() && size > 6 && size <= 30)
			do_size(size);
		else{
			cout << "ERROR: Expected an integer.\n";
			cin.clear();
			cin.ignore(100000, '\n');
		}
		return true;
	} else if(order.compare("zoom") == 0){
		cin >> num1;
		if(cin.good() && num1 >= 1)
			do_zoom(num1);
		else{
			cout << "ERROR: Expected an double.\n";
			cin.clear();
			cin.ignore(100000, '\n');
		}
		return true;
	} else if(order.compare("pan") == 0){
		cin >> num1 >> num2;
		if(cin.good())
			do_pan(num1, num2);
		else{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "ERROR: Expected an tow doubles.\n";
		}
		return true;
	}else if(order.compare("show") == 0){
		do_show();
		return true;
	}

	return false;
}

bool Controller::orderModel(string& order) {
	string name, type, place, x, y;
	int speed;
	double course;
	if(order.compare("status") == 0){
		status();
		return true;
	} else if (order.compare("go") == 0){
		go();
		return true;
	} else if (order.compare("create") == 0){
		cin >> name >> type;
		if(type.compare("Knight") == 0){
			cin >> place;
			createKnight(name, type, place);
		} else {
			cin >> x >> y;
			pair<double, double> loc(stod(x.substr(1,x.size() -2)),stod(y.substr(0,y.size() -1)));
			createAgent(name, type, loc);
		}
		return true;
	}else if(order.compare("exit") == 0)
		return true;
		else {
		shared_ptr<Agent> agent = findAgent(order);
		if(agent){
			cin >> type;
			if(type.compare("course") == 0){
				cin >> course;
				agent.get()->setCourse(course);
				if(findThug(order)){
					cin >> speed;
					agent.get()->setSpeed(speed);
				}
			}else if(type.compare("position") == 0){
				cin >> x >> y;
				pair<double, double> loc(stod(x.substr(1,x.size() -2)),stod(y.substr(0,y.size() -1)));
				if(typeid(agent.get()) == typeid(Thug)){
						cin >> speed;
						agent.get()->setSpeed(speed);
				}
				agent.get()->setPosition(loc);
			} else if(type.compare("destination") == 0){
				cin >> name;
				shared_ptr<Structure> s = findStruc(name);
				shared_ptr<Knight> k = findKnight(order);
				if(k && s)
					agent.get()->setDestination(s);
			}else if(type.compare("stop") == 0)
				agent.get()->stop();
			else if(type.compare("attack") == 0){
				cin >> name;
				shared_ptr<Peasant> peas = findPeas(name);
				shared_ptr<Thug> thug = findThug(order);
				if(thug && peas) {
					set<shared_ptr<Knight>> k = m.get()->getKnights();
					thug.get()->attack(peas, k);
				}
			}else if(type.compare("start_working") == 0){
				shared_ptr<Peasant> p = findPeas(order);
				cin >> type >> place;
				shared_ptr<Farm> f = findFarm(type);
				shared_ptr<Castle> c = findCastle(place);
				p.get()->start_working(f,c);
			}
			return true;

		}else
			cout << "Invalid command...\n";
			return true;
	}
	return false;
}

shared_ptr<Agent> Controller::findAgent(string& name) {
	set<shared_ptr<Agent> > agents = m.get()->getAgents();
	for(auto so : agents){
		if(so.get()->getName().compare(name) == 0){
			return so;
		}
	}
	return nullptr;
}

shared_ptr<Structure> Controller::findStruc(string& name) {
	set<shared_ptr<Structure> > struc = m.get()->getStructures();
	for(auto so : struc){
		if(so.get()->getName().compare(name) == 0){
			return so;
		}
	}
	return nullptr;

}


shared_ptr<Thug> Controller::findThug(string& name) {
	set<shared_ptr<Thug> > thug = m.get()->getThugs();
	for(auto so : thug){
		if(so.get()->getName().compare(name) == 0){
			return so;
		}
	}
	return nullptr;

}

shared_ptr<Peasant> Controller::findPeas(string& name) {
	set<shared_ptr<Peasant> > peas = m.get()->getPeasants();
	for(auto so : peas){
		if(so.get()->getName().compare(name) == 0){
			return so;
		}
	}
	return nullptr;

}

shared_ptr<Farm> Controller::findFarm(string& name) {
	set<shared_ptr<Farm> > farms = m.get()->getFarms();
			for(auto so : farms){
				if(so.get()->getName().compare(name) == 0){
					return so;
				}
			}
			return nullptr;
}

shared_ptr<Castle> Controller::findCastle(string& name) {
	set<shared_ptr<Castle> > castles = m.get()->getCastles();
			for(auto so : castles){
				if(so.get()->getName().compare(name) == 0){
					return so;
				}
			}
			return nullptr;
}


void Controller::controller() {
	string order ="null";

	do {
		cout << "Time " << m.get()->getTime() << ": Enter command: ";
		cin >> order;
		if(!orderView(order))
			if(!orderModel(order))
				throw exception();

	} while(order.compare("exit") != 0);
}

shared_ptr<Knight> Controller::findKnight(string& name) {
	set<shared_ptr<Knight> > knights = m.get()->getKnights();
		for(auto so : knights){
			if(so.get()->getName().compare(name) == 0){
				return so;
			}
		}
		return nullptr;
}
