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

void HQ::addMember()
{
	string m_name;

	cout << "Member's name: ";
	getline(cin, m_name);

	for (unsigned int i = 0; i < members.size(); i++)
		if (members[i]->getName() == m_name)
			throw(Another_member(m_name));

	Member *m = new Member(m_name);

	members.push_back(m);
}

void HQ::removeMember()
{
	string m_name;

	cout << "Member's name: ";
	getline(cin, m_name);

	for (unsigned int i = 0; i < members.size(); i++)
		if (members[i]->getName() == m_name)
		{
			members.erase(members.begin() + i);
			return;
		}

	cout << "There isn't any member with that name.\n";
}

void HQ::addStation()
{
	string nm;
	int n_mxs, x_coord, y_coord;
	
	cout << endl << "Name: ";
	getline(cin, nm);

	for (unsigned int i = 0; i < stations.size(); i++)
		if (stations[i]->getName() == nm)
			throw(Another_station(nm, stations[i]->getLocalization().first, stations[i]->getLocalization().second));

	cout << "Number of spots: ";
	cin >> n_mxs;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input. Please try again.\n";
		cin >> n_mxs;
	}

	cout << "X coordinates: ";
	cin >> x_coord;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input. Please try again.\n";
		cin >> x_coord;
	}

	cout << "Y coordinates: ";
	cin >> y_coord;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input. Please try again.\n";
		cin >> y_coord;
	}

	for (unsigned int i = 0; i < stations.size(); i++)
		if (stations[i]->getLocalization().first == x_coord && stations[i]->getLocalization().second == y_coord)
			throw(Another_station(stations[i]->getName(), x_coord, y_coord));

	Station *s = new Station(n_mxs, nm, x_coord, y_coord);

	stations.push_back(s);
}

void HQ::removeStation()
{
	string nm;

	cout << "Name: ";
	getline(cin, nm);

	for (unsigned int i = 0; i < stations.size(); i++)
		if (stations[i]->getName() == nm)
		{
			stations.erase(stations.begin() + i);
			return;
		}

	cout << "There isn't any station named " << nm << endl;
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

int HQ::find_Station(string name)
{
	for (unsigned int i = 0; i < stations.size(); i++)
		if (stations[i]->getName() == name)
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
			stations[i]->show_station();
			return;
		}

	cout << "Station not found\n";
}

void HQ::show_stations() const
{
	int n_rc = 0, n_ub = 0, n_us = 0, n_ch = 0;

	for (unsigned int i = 0; i < stations.size(); i++)
	{
		cout << stations[i]->getName() << endl
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
			<< "Racing: " << n_rc << endl << endl;
	}
}

void HQ::Reset_Members_MonthlyTime() 
{
	for (unsigned int i = 0; i < members.size(); i++)
		members[i]->setHours(0);
}

void HQ::Rand_Localization()
{
	srand(static_cast<unsigned int> (time(NULL)));

	for (unsigned int i = 0; i < active_users.size(); i++)
		active_users[i]->setLocalization(rand() % 15 + 1, rand() % 15 + 1);
}

void HQ::FastForward_Time(int month, int day, int hour, int minute, Date &global_date)
{
	Date init_date = global_date;

	global_date.addMonth(month);
	global_date.addDay(day);
	global_date.addHour(hour);
	global_date.addMinutes(minute);

	if (((global_date.getDay() > init_date.getDay()) && (init_date.getDay() < 27)) || (global_date.getMonth() > init_date.getMonth()))
		Reset_Members_MonthlyTime();

	Rand_Localization();
}

void HQ::Main_Menu(Date &global_date)
{
	int opt;
	
	

	do
	{
		system("cls");

		cout << "+----------------------------+\n"
			<< "|         RENT-A-BIKE        |\n"
			<< "+-------------+--------------+\n"
			<< "| 1 - Bikes   | 2 - Stations |\n"
			<< "+-------------+--------------+\n"
			<< "| 3 - Payment | 4 - Options  |\n"
			<< "+-------------+--------------+\n"
			<< "|      5 - Save and Exit     |\n"
			<< "+----------------------------+\n" << endl;

		cin >> opt;
		cin.clear();
		cin.ignore(1000, '\n');

		InvalidInput(5, opt);

		switch (opt)
		{
		case 1:
			Bikes_Menu();
			break;

		case 2:
			Station_Menu();
			break;

		case 3:
			Payment_Menu(global_date);
			break;

		case 4:
			Options_Menu(global_date);
			break;

		case 5:
			write_info();
			break;
		}

	} while (opt != 5);
}

void HQ::Bikes_Menu()
{
	int opt;

	do
	{
		cout << "+---------------+\n"
			<< "| 1 - Rent bike |\n"
			<< "+---------------+\n"
			<< "|  2 - Go back  |\n"
			<< "+---------------+\n" << endl;

		cin >> opt;

		InvalidInput(2, opt);
		cin.clear();
		cin.ignore(1000, '\n');

		try 
		{
			switch (opt)
			{
			case 1:
				RentBike();
				break;

			case 2:
				break;
			}
		}
		catch (Already_Active_User aau)
		{
			cout << endl << "User " << aau.getName() << " is already renting a bike.\n";
		}

	} while (opt != 2);
}

void HQ::Station_Menu()
{
	int opt;
	do
	{
		cout << "+--------------------------+-------------------+\n"
			<< "| 1 - Search station       | 2 - Show stations |\n"
			<< "+--------------------------+-------------------+\n"
			<< "| 3 - Show nearest station | 4 - Go back       |\n"
			<< "+--------------------------+-------------------+\n" << endl;

		cin >> opt;

		InvalidInput(4, opt);
		cin.clear();
		cin.ignore(1000, '\n');

		switch (opt)
		{
		case 1:
			Search_Station();
			break;

		case 2:
			show_stations();
			break;

		case 3:
			Nearest_Station();
			break;

		case 4:
			break;
		}
	} while (opt != 4);
}

void HQ::Payment_Menu(Date g_date)
{
	int opt;

	do
	{
		cout << "+-------------------+\n"
			<< "| 1 - Balance       |\n"
			<< "+-------------------+\n"
			<< "| 2 - Checkout bike |\n"
			<< "+-------------------+\n"
			<< "| 3 - Go back       |\n"
			<< "+-------------------+\n" << endl;

		cin >> opt;

		InvalidInput(3, opt);
		cin.clear();
		cin.ignore(1000, '\n');
		
		try
		{
			switch (opt)
			{
			case 1:
				Check_Balance(g_date);
				break;

			case 2:
				Check_out(g_date);
				break;

			case 3:
				break;
			}
		}
		catch (Not_Active_User nau)
		{
			cout <<  endl << "User " << nau.getName() << "hasn't rented a bike yet.\n";
		}
		catch (Inexistent_Station is)
		{
			cout << endl << is.getName() << "is not a station.\n";
		}
	} while (opt != 3);
}

void HQ::Options_Menu(Date &global_date)
{
	int opt;

	cout << "+------------------------+\n"
		<< "| 1 - Add/Remove member  |\n"
		<< "+------------------------+\n"
		<< "| 2 - Add/Remove station |\n"
		<< "+------------------------+\n"
		<< "| 3 - Fast forward       |\n"
		<< "+------------------------+\n"
		<< "| 4 - Redistribute bikes |\n"
		<< "+------------------------+\n" << endl;

	cin >> opt;
	InvalidInput(4, opt);
	cin.clear();
	cin.ignore(1000, '\n');

	switch (opt)
	{
		case 1:
			Add_remove_member_menu();
			break;

		case 2:
			Add_remove_station_menu();
			break;

		case 3:
			fast_forward_menu(*this, global_date);

		case 4:

			break;
	}
}

void HQ::Add_remove_member_menu()
{
	int opt;
	
	cout << "+-------------------+\n"
		<< "| 1 - Add member    |\n"
		<< "+-------------------+\n"
		<< "| 2 - Remove member |\n"
		<< "+-------------------+\n" << endl;

	cin >> opt;
	InvalidInput(2, opt);
	cin.clear();
	cin.ignore(1000, '\n');

	try
	{
		switch (opt)
		{
		case 1:
			addMember();
			break;
		case 2:
			removeMember();
			break;
		}
	}
	catch (Another_member)
	{
		cout << "There's already another member with the same name.\n";
	}
}

void HQ::Add_remove_station_menu()
{
	int opt;

	cout << "+--------------------+\n"
		<< "| 1 - Add station    |\n"
		<< "+--------------------+\n"
		<< "| 2 - Remove station |\n"
		<< "+--------------------+\n" << endl;

	cin >> opt;
	InvalidInput(2, opt);
	cin.clear();
	cin.ignore(1000, '\n');

	try
	{
		switch (opt)
		{
		case 1:
			addStation();
			break;

		case 2:
			removeStation();
			break;
		}
	}
	catch (Another_station as)
	{
		cout << "There's already a station named " << as.getName()
			<< "at " << as.getLocalization().first << "," << as.getLocalization().second << endl;
	}
}

void HQ::RentBike()
{
	string name, conf, type;
	int opt, p_im;
	unsigned int im;
	vector<Station *> vs;
	User *u;
	Station *closest_station;

	cout << "Username: ";
	getline(cin, name);

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input. Please try again.\n";
		getline(cin, name);
	}

	if (find_ActiveUser(name) != -1)
		throw(Already_Active_User(name));

	p_im = find_Member(name);

	if (p_im != -1)
	{
		im = p_im;
		u = getMembers()[p_im];
	}
	else
		u = new Regular(name);

	cout << "+------------------+\n"
		<< "|   Type of bike   |\n"
		<< "+------------------+\n"
		<< "|     1 - Urban    |\n"
		<< "+------------------+\n"
		<< "| 2 - Simple Urban |\n"
		<< "+------------------+\n"
		<< "|     3 - Child    |\n"
		<< "+------------------+\n"
		<< "|    4 - Racing    |\n"
		<< "+------------------+\n" << endl;

	cin >> opt;

	InvalidInput(4, opt);
	cin.clear();
	cin.ignore(1000, '\n');

	switch (opt)
	{
	case 1:
		type = "UB";
		vs = find_bike_type(type);
		break;

	case 2:
		type = "US";
		vs = find_bike_type(type);
		break;

	case 3:
		type = "CH";
		vs = find_bike_type(type);
		break;

	case 4:
		type = "RC";
		vs = find_bike_type(type);
		break;
	}

	if (vs.empty())
	{
		cout << "There aren't any stations with that bike type\n";
		return;
	}

	closest_station = u->getClosestStation(vs);
	cout << "The nearest station with that type of bike (" << closest_station->getName() << ") is "
		<< fixed << setprecision(2) << calc_distance(closest_station->getLocalization().first, closest_station->getLocalization().second,
			u->getLocalization().first, u->getLocalization().second)
		<< "km away. Are you sure you want to continue? (y/n)\n";

	cin >> conf;

	while (cin.fail() || (conf != "y" && conf != "n"))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input. Please try again.\n";
		cin >> conf;
	}

	if (conf == "y")
	{
		u->setLocalization(closest_station->getLocalization().first, closest_station->getLocalization().second);

		for (unsigned int i = 0; i < closest_station->getAvailableBikes().size(); i++)
			if (closest_station->getAvailableBikes()[i]->getID() == type)
			{
				u->addBike(closest_station->getAvailableBikes()[i], this);
				closest_station->removeBike(type);
				break;
			}
	}

	return;
}

void HQ::Search_Station() const
{
	string s_name;

	cout << "Station name: ";
	getline(cin, s_name);

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid Input. Please try again.\n";
		cin >> s_name;
	}

	search_station(s_name);
}

void HQ::Nearest_Station()
{
	string username;
	int i;
	User *u;

	cout << "Username: ";
	getline(cin, username);
	cout << endl;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input. Please try again.\n";
		cin >> username;
		cout << endl;
	}

	i = find_ActiveUser(username);

	if (i != -1)
		u = getActiveUsers()[i];
	else
	{
		i = find_Member(username);

		if (i != -1)
			u = getMembers()[i];
		else
			u = new Regular(username);
	}

	cout << "The neares station is: \n" << endl;
	u->getClosestStation(getStations())->show_station();
}

void HQ::Check_Balance(Date g_date)
{
	int i, n_hours;
	string username;

	cout << "Username: ";
	cin >> username;
	cout << endl;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input. Please try again.\n";
		cin >> username;
		cout << endl;
	}

	i = find_Member(username);

	if (i != -1)
	{
		cout << "You've accumulated " << members[i]->getHours() << " hours so far this month.\n";
		cout << "This month's bill: " << members[i]->getPrice() << endl;
	}
	else
	{
		i = find_ActiveUser(username);

		if (i != -1)
		{
			n_hours = g_date - active_users[i]->getBike()->getDate();

			cout << "Value to pay at checkout (so far): " << n_hours * active_users[i]->getPrice() << endl;
		}
		else
		{
			cout << "You aren't using a bike at this moment.\n";
			return;
		}
	}
}

void HQ::Check_out(Date g_date)
{
	vector<Station *> available_stations;
	string username, station_name;
	int i, j, st, opt, n_hours;
	bool member = false;
	User *u = NULL;
	Member *m = NULL;
	Station *s;

	for (unsigned int i = 0; i < getStations().size(); i++)
		if (getStations()[i]->getSpots() > 0)
			available_stations.push_back(getStations()[i]);

	cout << "Username: ";
	getline(cin, username);
	cout << endl;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input. Please try again.\n";
		cin >> username;
		cout << endl;
	}

	i = find_Member(username);
	j = find_ActiveUser(username);

	if (i != -1 && j != -1)
	{
		m = getMembers()[i];
		member = true;
	}
	else
	{
		if (j != -1)
			u = getActiveUsers()[j];
		else
			throw(Not_Active_User(username));
	}

	cout << "The closest station with available spots is: \n" << endl;
	
	if(member)
		s = m->getClosestStation(available_stations);
	else
		s = u->getClosestStation(available_stations);

	s->show_station();

	cout << "+------------------------------+\n"
		<< "| 1- Checkout at this location |\n"
		<< "+------------------------------+\n"
		<< "|  2 - Choose another station  |\n"
		<< "+------------------------------+\n" << endl;

	cin >> opt;

	InvalidInput(2, opt);
	cin.clear();
	cin.ignore(1000, '\n');

	switch (opt)
	{
	case 1:
		
		if (member)
		{
			m->Checkout(g_date);
			m->setLocalization(s->getLocalization().first, s->getLocalization().second);
			active_users.erase(active_users.begin() + i);
			s->addBike(m->getBike());
		}
		else
		{
			u->Checkout(g_date);
			u->setLocalization(s->getLocalization().first, s->getLocalization().second);
			active_users.erase(active_users.begin() + j);
			s->addBike(u->getBike());
		}
		
		break;

	case 2:
		cout << "Station name: ";
		getline(cin, station_name);

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input. Please try again.\n";
			cin >> station_name;
			cout << endl;
		}

		st = find_Station(station_name);

		if (st != -1)
			s = stations[i];
		else throw(Inexistent_Station(station_name));

		if (member)
		{
			m->Checkout(g_date);
			m->setLocalization(s->getLocalization().first, s->getLocalization().second);
			active_users.erase(active_users.begin() + i);
			s->addBike(m->getBike());
		}
		else
		{
			u->Checkout(g_date);
			u->setLocalization(s->getLocalization().first, s->getLocalization().second);
			active_users.erase(active_users.begin() + j);
			s->addBike(u->getBike());
		}
		
		break;
	}
}

void HQ::read_info(Date global_date)
{
	ifstream read;
	istringstream sstr;		
	string txt_line, comma, bike_id, s_name;
	int x, y, month_hours, i, month, day, hour, minute, max_spots;
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
		{
			member = true;
			active_users.push_back(getMembers()[i]);
		}
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
		sstr >> day >> comma >> month >> comma >> hour >> comma >> minute;
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
			ready_active_user->setLocalization(x, y);
			ready_active_user->addBike(user_bike, this);
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
		ready_station = new Station(max_spots, s_name, x, y);

		while(comma != ";")
		{
			sstr >> bike_id >> comma;
			
			if (bike_id == "US")
				station_bike = new Urban_simple_b(global_date);
			else
				if (bike_id == "UB")
					station_bike = new Urban_b(global_date);
				else
					if (bike_id == "CH")
						station_bike = new Child_b(global_date);
					else
						station_bike = new Race_b(global_date);

			ready_station->addBike(station_bike);
		}

		sstr.clear();
		stations.push_back(ready_station);
	}

	read.close();
}

void HQ::write_info() const
{
	ofstream write;
	unsigned int i, j;

	write.open("Active_Users.txt");

	for (i = 0; i < active_users.size(); i++)
	{
		write << active_users[i]->getName() << endl
			<< active_users[i]->getLocalization().first << " , " << active_users[i]->getLocalization().second << endl
			<< active_users[i]->getBike()->getID() << endl
			<< active_users[i]->getBike()->getDate().getDay() << " / "
			<< active_users[i]->getBike()->getDate().getMonth() << " ; "
			<< active_users[i]->getBike()->getDate().getHour() << " : "
			<< active_users[i]->getBike()->getDate().getMinutes() << endl;
	}

	write.close();
	write.open("Members.txt");

	for (i = 0; i < members.size(); i++)
	{
		write << members[i]->getName() << endl
			<< members[i]->getLocalization().first << " , " << members[i]->getLocalization().second << endl
			<< members[i]->getHours() << endl;
	}

	write.close();
	write.open("Stations.txt");

	for (i = 0; i < stations.size(); i++)
	{
		write << stations[i]->getName() << endl
			<< stations[i]->getLocalization().first << " , " << stations[i]->getLocalization().second << endl
			<< stations[i]->getMaxSpots() << endl;

		for (j = 0; j < stations[i]->getAvailableBikes().size() - 1; j++)
			write << stations[i]->getAvailableBikes()[j]->getID() << " , ";

		write << stations[i]->getAvailableBikes()[j]->getID() << " ;" << endl;
	}

	write.close();
}