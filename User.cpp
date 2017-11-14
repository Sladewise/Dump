#include "User.h"
#include "HQ.h"

using namespace std;

//User

User::User(string username)
{
	srand(time(NULL));
	Date null_date(1,1,0,0);
    Urban_simple_b *null_bike = new Urban_simple_b(null_date);
    bike = null_bike;
    name = username;
    active = false;
	Localization.first = rand() % 100 + 1;
	Localization.second = rand() % 100 + 1;
}

string User::getName() const
{
    return name;
}

pair<int, int> User::getLocalization() const
{
	return Localization;
}

void User::setName(string new_name)
{
	name = new_name;
}

void User::setLocalization(int x, int y)
{
	Localization.first = x;
	Localization.second = y;
}

void User::setBike(Bike *bk)
{
	bike = bk;
}

void User::addBike(Bike *bk, HQ *hq)
{
    bike = bk;
    active = true;
	hq->addActiveUser(this);
}

void User::removeBike()
{
    active = false;
}

Station* User::getClosestStation(vector<Station *> vs) const
{
	unsigned int i = 0, i_min = 0;
	pair<int, int> stat_loc = vs[i]->getLocalization();
	double min = sqrt(pow(stat_loc.first - Localization.first, 2) + pow(stat_loc.second - Localization.second, 2));

	for (i; i < vs.size(); i++)
	{
		stat_loc = vs[i]->getLocalization();

		if (sqrt(pow(stat_loc.first - Localization.first, 2) + pow(stat_loc.second - Localization.second, 2)) < min)
		{
			min = sqrt(pow(stat_loc.first - Localization.first, 2) + pow(stat_loc.second - Localization.second, 2));
			i_min = i;
		}
	}

	return vs[i_min];
}

//Member

Member::Member(string username) : User(username)
{
    total_monthly_time = 0;
}

void Member::setHours(int hours)
{
	total_monthly_time = hours;
}



//Regular

Regular::Regular(string username) : User(username) {}

//Already Active User

Already_Active_User::Already_Active_User(string name)
{
	this->name = name;
}

string Already_Active_User::getName() const
{
	return name;
}

