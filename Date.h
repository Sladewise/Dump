#ifndef P1_DATE_H
#define P1_DATE_H

#include <iostream>
#include <string>

using namespace std;





class Date
{
	int day;
	int month;
	int hour;
	int minutes;


public:
	
	Date(int day, int month, int hour, int minutes);
	int getDay();
	int getMonth();
	int getHour();
	int getMinutes();
	void setDay(int d);
	void setMonth(int m);
	void setHour(int h);
	void setMinutes(int min);
	void addHour(int h);

	



};









#endif //P1_DATE_H