/*
 * Model.h
 *
 *  Created on: 7 αιεμι 2020
 *      Author: Harel
 */

#ifndef MODEL_H_
#define MODEL_H_
#include "Thug.h"
#include "ViewBase.h"
#include <fstream>

class Model {
private:
	set<shared_ptr<SimObject>> all_objects;
	set<shared_ptr<Structure>> structures;
	set<shared_ptr<Farm>> farms;
	set<shared_ptr<Castle>> castles;
	set<shared_ptr<Peasant>> peasants;
	set<shared_ptr<Knight>> knights;
	set<shared_ptr<Thug>> thugs;
	set<shared_ptr<Agent>> agents;
	shared_ptr<ViewBase> vb;
	int time;
	static Model* instance;
	void createCastles(const char* file);
	void createFarms(const char* file);
	Model() : time(0){} // @suppress("Class members should be properly initialized")
public:
	void print();
	static Model* getInstance();
	void createStructure(int argc, char* argv[]);
	void update() {for(auto so : all_objects)so.get()->update(); time++;}
	void addKnight(shared_ptr<Knight>& agent, const string& type);
	void addThug(shared_ptr<Thug>& agent, const string& type);
	void addPeasant(shared_ptr<Peasant>& agent, const string& type);
	virtual ~Model() {
	}
	const set<shared_ptr<SimObject> >& getAllObject() const {
		return all_objects;
	}

	void setAllObject(const set<shared_ptr<SimObject> >& allObject) {
		all_objects = allObject;
	}

	const set<shared_ptr<Castle> >& getCastles() const {
		return castles;
	}

	void setCastles(const set<shared_ptr<Castle> >& castles) {
		this->castles = castles;
	}

	const set<shared_ptr<Farm> >& getFarms() const {
		return farms;
	}

	void setFarms(const set<shared_ptr<Farm> >& farms) {
		this->farms = farms;
	}

	set<shared_ptr<Knight>>& getKnights(){
		return knights;
	}

	void setKnights(const set<shared_ptr<Knight> >& knights) {
		this->knights = knights;
	}

	const set<shared_ptr<Peasant> >& getPeasants() const {
		return peasants;
	}

	void setPeasants(const set<shared_ptr<Peasant> >& peasants) {
		this->peasants = peasants;
	}

	const set<shared_ptr<Thug> >& getThugs() const {
		return thugs;
	}

	void setThugs(const set<shared_ptr<Thug> >& thugs) {
		this->thugs = thugs;
	}

	int getTime() const {
		return time;
	}

	void setTime(int time) {
		this->time = time;
	}

	void attach(shared_ptr<ViewBase>& vb){ this->vb = vb;}
	void detach(){ vb.reset();}

	const set<shared_ptr<Agent> >& getAgents() const {
		return agents;
	}

	const set<shared_ptr<Structure> >& getStructures() const {
		return structures;
	}
};

#endif /* MODEL_H_ */
