#include "Station.h"

using namespace std;

Station::Station(int max_spots,string name, int x, int y)
{
    vector<Bike *> empty_available_bikes;

    no_max_spots = max_spots;
    this->name = name;
    available_bikes = empty_available_bikes;
	Localization.first = x;
	Localization.second = y;
}

void Station::addBike(Bike *bk)
{
	available_bikes.push_back(bk);
}

void Station::removeBike(string bike_id)
{
	for (unsigned int i = 0; i < available_bikes.size(); i++)
		if (bike_id == available_bikes[i]->getID())
			available_bikes.erase(available_bikes.begin() + i);
}

vector<Bike *> Station::getAvailableBikes() const
{
	return available_bikes;
}

bool Station::findBike(string type) const
{
	for (unsigned int i = 0; i < available_bikes.size(); i++)
		if(available_bikes[i]->getID() == type)
			return true;
		
	return false;
}

pair<int, int> Station::getLocalization() const
{
	return Localization;
}

string Station::getName() const
{
	return name;
}

int Station::getMaxSpots() const
{
	return no_max_spots;
}

