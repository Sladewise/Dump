#include "HQ.h"

using namespace std;

HQ::HQ()
{
    vector<Member*> empty_members;
    vector<User*> empty_active_users;
    vector <Station *> empty_stations;

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

vector<Station *> HQ::getStations() const
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

vector<Station *> HQ::find_bike_type(string type) const
{
	vector<Station *> confirmed_stations;
	
	for (unsigned int i = 0; i < stations.size(); i++)
		if (stations[i]->findBike(type))
			confirmed_stations.push_back(stations[i]);

	return confirmed_stations;
}

void HQ::search_station(string name) const
{
	int n_rc = 0, n_ub = 0, n_us = 0, n_ch = 0;
	
	for (unsigned int i = 0; i < stations.size(); i++)
		if (stations[i]->getName() == name)
		{
			cout << name << endl
				<< endl
				<< "Coordinates: " << stations[i]->getLocalization().first << ", " << stations[i]->getLocalization().second
				<< endl
				<< "Maximum capacity: " << stations[i]->getMaxSpots() << endl
				<< "No of available spots: " << stations[i]->getMaxSpots() - stations[i]->getAvailableBikes().size() << endl
				<< "Available Bikes:\n";

			for (unsigned int j = 0; j < stations[i]->getAvailableBikes().size(); j++)
				if (stations[i]->getAvailableBikes()[j]->getID() == "US") //Might need to change
					n_us++;
				else
					if (stations[i]->getAvailableBikes()[j]->getID() == "UB")
						n_ub++;
					else
						if (stations[i]->getAvailableBikes()[j]->getID() == "CH")
							n_ch++;
						else
							if (stations[i]->getAvailableBikes()[j]->getID() == "RC")
								n_rc++;

			cout << "Urban: " << n_ub << endl
				<< "Simple urban: " << n_us << endl
				<< "Child: " << n_ch << endl
				<< "Racing: " << n_rc << endl;

			return;
		}

	cout << "Station not found\n";
}





