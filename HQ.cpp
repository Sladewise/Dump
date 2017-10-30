#include "HQ.h"
#include <iostream>
#include "User.h"
#include <vector>
#include "Station.h"

using namespace std;

HQ::HQ()
{
    vector<Member> empty_members;
    vector<User> empty_active_users;
    vector <Station> empty_stations;

    members = empty_members;
    active_users = empty_active_users;
    stations = empty_stations;
}

