#ifndef P1_BIKE_H
#define P1_BIKE_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;




//////////////////////BIKE/////////////////////////////////
class Bike
{
protected:
	string ID;
	Date start_date;
	static int id_counter;

public:
	Bike( Date start_date);
	void setID(string Id);
	Date getDate();
	virtual double getPrice() = 0;
	string getID() ;
};




////////////////////URBAN BIKE/////////////////////////////
class Urban_b : public Bike
{
	static double price_h; 

public:
	
	Urban_b( Date start_date);
	double getPrice();
	
	

};


/////////////////URBAN SIMPLE BIKE/////////////////////////
class Urban_simple_b : public Bike
{
	static double price_h;

public:
	Urban_simple_b( Date start_date);
	double getPrice();

};

/////////////////////RACE BIKE///////////////////////////
class Race_b : public Bike
{
	static double price_h;

public:
	Race_b( Date start_date);
	double getPrice();
	
};

///////////////////CHILD BIKE//////////////////////////////
class Child_b : public Bike
{
	static double price_h;

public:
	Child_b( Date start_date);
	double getPrice();
	
};


#endif //P1_BIKE_H