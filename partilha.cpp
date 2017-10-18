#include "partilha.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

//HQ Class

HQ::HQ()
{
    vector<Member> empty_members;
    vector<User> empty_active_users;
    vector <Station> empty_stations;

    members = empty_members;
    active_users = empty_active_users;
    stations = empty_stations;
}

//Class Bike

//Class Station

Station::Station(int max_spots,string localization)
{
    vector<Bike> empty_available_bikes;

    no_max_spots = max_spots;
    position = localization;
    available_bikes = empty_available_bikes;
}

//Class User

User::User(string username)
{
    name = username;
    active = false;
}

Member::Member(string username) : User(username)
{
    total_monthly_time = 0;
}

Regular::Regular(string username) : User(username) {}

