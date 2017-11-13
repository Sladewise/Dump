#include "Bike.h"
#include <iostream>
#include <vector>
#include<string>


using namespace std;


Date global_date(3,3,5,3);


//////////////////////BIKE/////////////////////////////////
Bike::Bike( Date start_date) :  start_date(start_date)
{


}

void Bike::setID(string id)
{
	this->ID = id;
}

Date Bike::getDate()
{
	return start_date;
}
int Bike::id_counter = 0;
string Bike::getID()

{

	return ID;
}

////////////////////URBAN BIKE/////////////////////////////
Urban_b::Urban_b(Date start_date) :Bike(start_date)
{



	string id;
	



	this->id_counter++;

	id = "UB" + to_string(this->id_counter);
	
	setID(id);

	


	

}

double Urban_b::getPrice()
{
	return price_h *  (global_date - getDate());
}

double Urban_b::price_h = 10;






/////////////////URBAN SIMPLE BIKE/////////////////////////
Urban_simple_b::Urban_simple_b( Date start_date):Bike(start_date) 
{
	string id;

	this->id_counter++;

	id = "US" + to_string(this->id_counter);

	setID(id);

}

double Urban_simple_b::getPrice()
{
	return price_h *  (global_date - getDate());
}


double Urban_simple_b::price_h = 11;



/////////////////////RACE BIKE///////////////////////////

Race_b::Race_b( Date start_date) : Bike(start_date)
{
	string id;

	this->id_counter++;

	id = "RC" + to_string(this->id_counter);

	setID(id);
}

double Race_b::getPrice()
{
	return price_h *  (global_date - getDate());
}

double Race_b::price_h = 12;



///////////////////CHILD BIKE//////////////////////////////
Child_b::Child_b( Date start_date) : Bike(start_date)
{
	string id;

	this->id_counter++;

	id = "CH" + to_string(this->id_counter);

	setID(id);
}

double Child_b::getPrice()
{
	return price_h *  (global_date - getDate());
}
double Child_b::price_h = 13;
