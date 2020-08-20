/*
 * Controller.h
 *
 *  Created on: 21 αιεμι 2020
 *      Author: Harel
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Model.h"

class Controller {
private:
	unique_ptr<Model> m;
	shared_ptr<ViewBase> v;
	bool orderView(string& order);
	bool orderModel(string& order);
	shared_ptr<Agent> findAgent(string& name);
	shared_ptr<Structure> findStruc(string& name);
	shared_ptr<Thug> findThug(string& name);
	shared_ptr<Knight> findKnight(string& name);
	shared_ptr<Peasant> findPeas(string& name);
	shared_ptr<Farm> findFarm(string& name);
	shared_ptr<Castle> findCastle(string& name);
public:
	Controller(Model* m, ViewBase* vb);
	void do_default(){ v.get()->do_default();}
	void do_size(int size){ v.get()->setSize(size);}
	void do_zoom(double zoom){ v.get()->setScale(zoom);}
	void do_pan(double x, double y){ v.get()->setOrigin(make_pair(x, y));}
	void do_show(){v.get()->setObjects(m.get()->getAllObject()); v.get()->show();}
	void status(){m.get()->print();}
	void go(){m.get()->update();}
	void createAgent(string& name, const string& type, pair<double, double>& location);
	void createKnight(string& name, const string& type, const string& place);
	void controller();
	virtual ~Controller(){m.reset();}
};

#endif /* CONTROLLER_H_ */
