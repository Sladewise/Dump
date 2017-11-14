#include "Funcs.h"

using namespace std;

void Main_Menu(HQ hq)
{
    int opt;

    do
    {
		cout << "+-------------+--------------+\n"
			<< "| 1 - Bikes   | 2 - Stations |\n"
			<< "+-------------+--------------+\n"
			<< "| 3 - Payment | 4 - Options  |\n"
			<< "+-------------+--------------+\n"
			<< "|      5 - Save and Exit     |\n"
			<< "+----------------------------+\n" << endl;

        cin >> opt;

        InvalidInput(5, opt);

        switch(opt)
        {
            case 1:
                Bikes_Menu(hq);
                break;

            case 2:
                Station_Menu(hq);
                break;

            case 3:

                break;

            case 4:

                break;

            case 5:
				hq.write_info();
                break;

            default:
                break;
        }

    }while(opt != 5);
}

void Bikes_Menu(HQ hq)
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

        switch(opt)
        {
            case 1:
				RentBike(hq);
                break;

            case 2:
                break;

            default:
                break;
        }
    }while(opt != 2);
}

void Station_Menu(HQ hq)
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

        switch(opt)
        {
            case 1:
				Search_Station(hq);
                break;

            case 2:
				hq.show_stations();
                break;

            case 3:
				Nearest_Station(hq);
                break;

            case 4:
                break;

            default:
                break;
        }
    }while(opt != 4);
}

void Payment_Menu()
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

        switch(opt)
        {
            case 1:

                break;

            case 2:

                break;

            default:
                break;
        }
    }while(opt != 3);
}

void InvalidInput(int n_op, int &op)
{
    while(cin.fail() || (op < 1 || op > n_op))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Invalid option! Please try again\n" << endl;
        cin >> op;
    }
}

void RentBike(HQ hq)
{
	string name, conf, type;
	int opt, p_im;
	unsigned int im;
	vector<Station *> vs;
	User *u;
	Station *closest_station;

	cout << "Username: ";
	cin >> name;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input. Please try again.\n";
		cin >> name;
	}

	if (hq.find_ActiveUser(name) != -1)
		throw(Already_Active_User(name));

	p_im = hq.find_Member(name);

	if (p_im != -1)
	{
		im = p_im;
		u = hq.getMembers()[p_im];
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

	switch (opt)
	{
		case 1:
			type = "UB";
			vs = hq.find_bike_type(type);
			break;

		case 2:
			type = "US";
			vs = hq.find_bike_type(type);
			break;

		case 3:
			type = "CH";
			vs = hq.find_bike_type(type);
			break;

		case 4:
			type = "RC";
			vs = hq.find_bike_type(type);
			break;
	}

	if (vs.empty())
	{
		cout << "There aren't any stations with that bike type\n";
		return;
	}
	
	closest_station = u->getClosestStation(vs);
	cout << "The nearest station with that type of bike (" << closest_station->getName() << ") is "
		<< calc_distance(closest_station->getLocalization().first, closest_station->getLocalization().second, 
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
				u->addBike(closest_station->getAvailableBikes()[i], &hq);
				closest_station->removeBike(type);
				break;
			}
	}
	
	return;
}

void Search_Station(HQ hq)
{
	string s_name;

	cout << "Station name: ";
	cin >> s_name;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid Input. Please try again.\n";
		cin >> s_name;
	}

	hq.search_station(s_name);
}

double calc_distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void Nearest_Station(HQ hq)
{
	string username;
	int x2, y2, i;
	double smallest_distance, tmp_distance;
	
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

	i = hq.find_ActiveUser(username);

	if(i != -1)
	{
		x2 = hq.getActiveUsers()[i]->getLocalization().first;
		y2 = hq.getActiveUsers()[i]->getLocalization().second;
	}
	else
	{
		i = hq.find_Member(username);

		if (i != -1)
		{
			x2 = hq.getMembers()[i]->getLocalization().first;
			y2 = hq.getMembers()[i]->getLocalization().second;
		}
		else
		{
			User *u = new Regular(username);
			x2 = u->getLocalization().first;
			y2 = u->getLocalization().second;
		}
	}

	smallest_distance = calc_distance(hq.getStations()[0]->getLocalization().first,
		hq.getStations()[0]->getLocalization().second, x2, y2);

	i = 0;

	for (unsigned int j = 0; j < hq.getStations().size(); j++)
	{
		tmp_distance = calc_distance(hq.getStations()[j]->getLocalization().first,
			hq.getStations()[j]->getLocalization().second, x2, y2);

		if (tmp_distance < smallest_distance)
		{
			smallest_distance = tmp_distance;
			i = j;
		}
	}

	cout << "The neares station is: \n" << endl;
	hq.search_station(hq.getStations()[i]->getName());
}









