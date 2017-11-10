#include "HQ.h"

using namespace std;

HQ::HQ()
{
    vector<Member*> empty_members;
    vector<User*> empty_active_users;
    vector <Station> empty_stations;

    members = empty_members;
    active_users = empty_active_users;
    stations = empty_stations;
}

void HQ::addActiveUser(User *user)
{
	active_users.push_back(user);
}

vector<User *> HQ::getActiveUsers() const
{
	return active_users;
}

vector<Member *> HQ::getMembers() const
{
	return members;
}

vector<Station> HQ::getStations() const
{
	return stations;
}

int HQ::find_Member(string name)
{
	for (unsigned int i = 0; i < members.size(); i++)
		if (members[i]->getName() == name)
			return i;

	return -1;
}

int HQ::find_ActiveUser(string name)
{
	for (unsigned int i = 0; i < active_users.size(); i++)
		if (active_users[i]->getName() == name)
			return i;

	return -1;
}

vector<Station> HQ::find_bike_type(string type) const
{
	vector<Station> confirmed_stations;
	
	for (unsigned int i = 0; i < stations.size(); i++)
		if (stations[i].findBike(type))
			confirmed_stations.push_back(stations[i]);

	return confirmed_stations;
}



