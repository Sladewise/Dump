#ifndef P1_STATION_H
#define P1_STATION_H

class Station
{
    int no_max_spots;
    string position;
    vector<Bike> available_bikes;

public:
    Station(int max_spots, string localization);
    void Menu() const;
    bool findBike(Bike bike) const;
};

#endif //P1_STATION_H
