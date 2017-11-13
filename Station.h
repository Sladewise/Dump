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
    string position;
    vector<Bike *> available_bikes;
	pair <int, int> Localization;

public:
    Station(int max_spots, string localization, int x, int y);
    bool findBike(string type) const;
	pair<int, int> getLocalization() const;
	vector<Bike *> getAvailableBikes() const;
};

#endif

