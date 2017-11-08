#ifndef P1_STATION_H
#define P1_STATION_H

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

public:
    Station(int max_spots, string localization);
    void Menu() const;
    bool findBike(Bike *bike) const;
};

#endif //P1_STATION_H
