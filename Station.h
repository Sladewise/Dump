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
	pair <unsigned int, unsigned int> Localization;
	
public:
    Station(int max_spots, string name, unsigned int x, unsigned int y);
    bool findBike(string type) const;
	void addBike(Bike *bk);
	void removeBike(string bike_id);
	pair<unsigned int, unsigned int> getLocalization() const;
	vector<Bike *> getAvailableBikes() const;
	string getName() const;
	int getMaxSpots() const;
	int getSpots() const;
	void show_station() const;
	bool operator==(const Station *s) const;
};

class Inexistent_Station
{
	string name;

public:
	Inexistent_Station(string nm);
	string getName() const;
};

class Another_station
{
	string name;
	pair<unsigned int, unsigned int> Localization;

public:
	Another_station(string nm, unsigned int x, unsigned int y);
	string getName() const;
	pair<unsigned int,unsigned int> getLocalization() const;
};

#endif

