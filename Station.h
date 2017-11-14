#ifndef AEDA_P1_STATION_H
#define AEDA_P1_STATION_H

#include <iostream>
#include <string>
#include <vector>
#include "Bike.h"

using namespace std;

class Station
{
    int no_max_spots;
	string name;
    vector<Bike *> available_bikes;
	pair <int, int> Localization;
	
public:
    Station(int max_spots, string name, int x, int y);
    bool findBike(string type) const;
	void addBike(Bike *bk);
	void removeBike(string bike_id);
	pair<int, int> getLocalization() const;
	vector<Bike *> getAvailableBikes() const;
	string getName() const;
	int getMaxSpots() const;
};

#endif

