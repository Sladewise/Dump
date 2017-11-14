#include "HQ.h"

using namespace std;

Date g_date(9, 11, 10, 1); //EFEITOS DE TESTE ONLY

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

void HQ::read_info()
{
	ifstream read;
	istringstream sstr;
	string txt_line, comma, bike_id, s_name;
	int x, y, month_hours, i, month, day, hour, minute, max_spots;
	double price_to_pay;
	bool member = false;
	Bike *user_bike, *station_bike;
	User *ready_active_user = new User("null");
	Station *ready_station;

	read.open("Members.txt");

	while (getline(read, txt_line))
	{
		Member *ready_member = new Member(txt_line);

		getline(read, txt_line);
		sstr.str(txt_line);
		sstr >> x >> comma >> y;
		sstr.clear();
		getline(read, txt_line);
		sstr.str(txt_line);
		sstr >> month_hours;
		sstr.clear();
		getline(read, txt_line);
		sstr.str(txt_line);
		sstr >> price_to_pay;
		sstr.clear();
		ready_member->setLocalization(x, y);
		ready_member->setHours(month_hours);

		members.push_back(ready_member);
	}

	read.close();
	read.open("Active_Users.txt");

	while (getline(read, txt_line))
	{
		i = find_Member(txt_line);

		if (i != -1)
			member = true;
		else
			ready_active_user = new User(txt_line);

		getline(read, txt_line);
		sstr.str(txt_line);
		sstr >> x >> comma >> y;
		sstr.clear();
		getline(read, txt_line);
		sstr.str(txt_line);
		sstr >> bike_id;
		sstr.clear();
		getline(read, txt_line);
		sstr.str(txt_line);
		sstr >> month >> comma >> day >> comma >> hour >> comma >> minute;
		sstr.clear();
		Date bike_date(month, day, hour, minute);
		
		if (bike_id == "US")
			user_bike = new Urban_simple_b(bike_date);
		else
			if (bike_id == "UB")
				user_bike = new Urban_b(bike_date);
			else
				if (bike_id == "CH")
					user_bike = new Child_b(bike_date);
				else
					user_bike = new Race_b(bike_date);

		if (member)
			members[i]->setBike(user_bike);
		else
		{
			ready_active_user->addBike(user_bike, this);
			active_users.push_back(ready_active_user);
		}
	}

	read.close();
	read.open("Stations.txt");

	while (getline(read, txt_line))
	{
		s_name = txt_line;

		getline(read, txt_line);
		sstr.str(txt_line);
		sstr >> x >> comma >> y;
		sstr.clear();
		getline(read, txt_line);
		sstr.str(txt_line);
		sstr >> max_spots;
		sstr.clear();
		getline(read, txt_line);
		sstr.str(txt_line);
		sstr.clear();
		ready_station = new Station(max_spots, s_name, x, y);

		comma = "";

		while(comma != ";")
		{
			sstr >> bike_id >> comma;
			
			if (bike_id == "US")
				station_bike = new Urban_simple_b(g_date);
			else
				if (bike_id == "UB")
					station_bike = new Urban_b(g_date);
				else
					if (bike_id == "CH")
						station_bike = new Child_b(g_date);
					else
						station_bike = new Race_b(g_date);

			ready_station->addBike(station_bike);
		}
	}

	read.close();

	
}





