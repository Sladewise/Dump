#ifndef AEDA_P1_USER_H
#define AEDA_P1_USER_H

#include "Bike.h"
#include "Station.h"

using namespace std;

class HQ;

class User
{
    bool active;
    Bike *bike;
    string name;
	pair <int, int> Localization;

public:
    User(string username);
	void setName(string new_name);
	void setLocalization(int x, int y);
	string getName() const;
	pair<int, int> getLocalization() const;
    Station* getClosestStation(vector<Station *> vs) const; //Args still need to be discussed
    void addBike(Bike *bk, HQ *hq);
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

class Already_Active_User
{
	string name;

public:
	Already_Active_User(string name);
	string getName() const;
};

#endif

