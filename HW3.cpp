//============================================================================
// Name        : HW3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Controller.h"


int main(int argc, char* argv[]) {
	try{
	Model* m = Model::getInstance();
	m->createStructure(argc, argv);
	ViewBase* vb = new ViewBase;
	Controller* c = new Controller(m,vb);
	c->controller();
	delete c;
	} catch(...){
		cout << "Input Error\n";
		exit(1);
	}
	return 0;
}
