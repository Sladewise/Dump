#include "Station.h"

using namespace std;

Station::Station(int max_spots,string localization)
{
    vector<Bike *> empty_available_bikes;

    no_max_spots = max_spots;
    position = localization;
    available_bikes = empty_available_bikes;
}

