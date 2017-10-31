#include "Bike.h"
#include <iostream>
#include <vector>
#include<string>


using namespace std;


//////////////////////BIKE/////////////////////////////////
Bike::Bike(string ID, Date start_date) : ID(ID), start_date(start_date)
{};





////////////////////URBAN BIKE/////////////////////////////
Urban_b::Urban_b(string ID, Date start_date, double price_h) :Bike(ID, start_date), price_h(price_h)
{}

double Urban_b::getPrice()
{
	return price_h; // *  (current Date - start date);
}




/////////////////URBAN SIMPLE BIKE/////////////////////////
Urban_simple_b::Urban_simple_b(string ID, Date start_date, double price_h):Bike(ID,  start_date) , price_h(price_h)
{}

double Urban_simple_b::getPrice()
{
	return price_h; // *  (current Date - start date);
}





/////////////////////RACE BIKE///////////////////////////

Race_b::Race_b(string ID, Date start_date, double price_h) : Bike(ID,start_date), price_h(price_h)
{}

double Race_b::getPrice()
{
	return price_h; // *  (current Date - start date);
}



///////////////////CHILD BIKE//////////////////////////////
Child_b::Child_b(string ID, Date start_date, double price_h) : Bike(ID,start_date), price_h(price_h)
{}

double Child_b::getPrice()
{
	return price_h; // *  (current Date - start date);
}