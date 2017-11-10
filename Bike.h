#ifndef AEDA_P1_BIKE_H
#define AEDA_P1_BIKE_H

#include <vector>
#include "Date.h"

using namespace std;




//////////////////////BIKE/////////////////////////////////
class Bike
{
	string ID;
	Date start_date;

public:
	Bike(string ID, Date start_date);
	Date getDate();
	virtual double getPrice() = 0;
};

////////////////////URBAN BIKE/////////////////////////////
class Urban_b : public Bike
{
	double price_h; 

public:
	Urban_b(string ID, Date start_date, double price_hour);
	double getPrice();

};

/////////////////URBAN SIMPLE BIKE/////////////////////////
class Urban_simple_b : public Bike
{
	double price_h;

public:
	Urban_simple_b(string ID, Date start_date, double price_hour);
	double getPrice();
};

/////////////////////RACE BIKE///////////////////////////
class Race_b : public Bike
{
	double price_h;

public:
	Race_b(string ID, Date start_date, double price_hour);
	double getPrice();
};

///////////////////CHILD BIKE//////////////////////////////
class Child_b : public Bike
{
	double price_h;

public:
	Child_b(string ID, Date start_date, double price_hour);
	double getPrice();
};

#endif
