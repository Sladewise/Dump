#include "User.h"
#include "HQ.h"

using namespace std;

//User

User::User(string username)
{
    Date null_date(1,1,0,0);
    Urban_simple_b *null_bike = new Urban_simple_b("00",null_date,0);
    bike = null_bike;
    name = username;
    active = false;
}

string User::getName() const
{
    return name;
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

//Member

Member::Member(string username) : User(username)
{
    total_monthly_time = 0;
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

