#ifndef P1_BIKE_H
#define P1_BIKE_H

#include <iostream>
#include <string>

using namespace std;

class Bike
{
    string ID;
    time_t time_start;

public:

    virtual double getPrice();
};

class Urban_b: public Bike
{
    double price_hour;

public:
    double getPrice();
};

class Urban_simple_b: public Bike
{
    double price_h;

public:
    double getPrice();
};

class Race_b: public Bike
{
    double price_h;

public:
    double getPrice();
};

class Child_b: public Bike
{
    double price_h;

public:
    double getPrice();
};

#endif //P1_BIKE_H
