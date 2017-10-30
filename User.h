#ifndef P1_USER_H
#define P1_USER_H

#include <iostream>
#include "Bike.h"
#include "Station.h"

class User
{
    bool active;
    Bike bike;
    string name;

public:
    User(string username);
    string getName();
    Station getClosestStation(); //Args still need to be discussed
    void addBike(Bike bk);
    void removeBike();
};

class Member: public User
{
    int total_monthly_time;
    static double price_month;

public:
    Member(string username);
    double getPrice();

};

class Regular: public User
{
    static double price_hour;
public:
    Regular(string username);
    double getPrice();
};


#endif //P1_USER_H
