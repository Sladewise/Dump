#include "Station.h"
#include <iostream>
#include "Bike.h"
#include <vector>

using namespace std;

Station::Station(int max_spots,string localization)
{
    vector<Bike> empty_available_bikes;

    no_max_spots = max_spots;
    position = localization;
    available_bikes = empty_available_bikes;
}

void Station::Menu() const
{

}

bool findBike(Bike bike) const
{

}

