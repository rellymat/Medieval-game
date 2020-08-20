/*
 * ViewBase.cpp
 *
 *  Created on: 21 αιεμι 2020
 *      Author: Harel
 */

#include "ViewBase.h"

ViewBase::ViewBase() {
	do_default();
	connected = false;
}

void ViewBase::show() {
	createMap();
	addObjectToMap();
	cout << "Display size: " << size << ", scale: " << scale << ", origin: ("
			<< origin.first << ", " << origin.second << ")\n";
	for (int i = 0; i < size + 1; ++i) {
		for (int j = 0; j < size + 1; ++j)
			cout << world[i][j] << " ";
		cout << endl;
	}
}

void ViewBase::createMap() {
	world = new string*[size + 1];
	for (int i = 0; i < size + 1; ++i)
		world[i] = new string[size + 1];

	for (int i = 0; i < size; ++i)
		for (int j = 1; j < size + 1; ++j)
			world[i][j] = " .";

	double max = scale * size - scale + origin.second;
	ostringstream strs;
	for (int i = 0; i < size; ++i) {
		if (i % 3 == 0) {
			strs << max;
			world[i][0] = strs.str();
			if (max < 10 && max > -1)
				world[i][0] += " ";
			max -= scale * 3;
		} else
			world[i][0] = "  ";
		if (i % 3 != 0 && i == size - 1) {
			max = origin.first;
			strs << max;
			world[i][0] = strs.str();
			if (max < 10 && max > -1)
				world[i][0] += " ";
		}
		strs.str(std::string());
	}

	max = origin.first;

	for (int i = 0; i < size + 1; ++i) {
		if (i % 3 == 1) {
			strs << max;
			if (max < 10 && max > -1)
				world[size][i] += " ";
			world[size][i] += strs.str();
			max += scale * 3;
		} else
			world[size][i] = "  ";
		if (i % 3 != 1 && i == size){
			max =  scale * size - scale + origin.second;
			strs << max;
			world[size][i] = " " + strs.str();
		}
		strs.str(std::string());
	}

}

void ViewBase::addObjectToMap() {
	int row, col, count = 0;
	for(auto so : objects){
		pair<double, double> loc = so.get()->getLocation();
		if(loc.first > size*scale - scale + origin.second || loc.first < origin.second  || loc.second > size*scale - scale + origin.first || loc.second < origin.first  )
			continue;
		else{
			loc.first = loc.first - (int)loc.first > 0.5 ? (int)loc.first + 1 : (int)loc.first;
			loc.second = loc.second - (int)loc.second > 0.5 ? (int)loc.second + 1 : (int)loc.second;
			count = 0;
			for (double i = origin.second;  i < scale * size - scale + origin.second + 1; i += scale) {
				if(i - loc.first >= 0){
					col = abs( i - loc.first) < abs(i - scale - loc.first) ? ++count : count;
					break;
				}
				count++;
			}
			count = 0;
			double max = scale * size - scale + origin.second;
			for (double i = max; i >= origin.first; i -= scale){
				if(i - loc.second <= 0){
					row = abs(i - loc.second) < abs(i + scale - loc.first)  ? count : ++count;
					break;
				}
				count++;
			}
		}
		world[row][col] = so.get()->getName().substr(0,2);
	}
}

ViewBase::~ViewBase() {

}

void ViewBase::do_default() {
	size = 25;
	scale = 2;
	origin = make_pair(0, 0);
	createMap();
}
