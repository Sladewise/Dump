#include "User.h"

using namespace std;

User::User(string username)
{
    Date null_date(1,1,0,0);
    Urban_simple_b *null_bike = new Urban_simple_b("00",null_date,0);
    bike = null_bike;
    name = username;
    active = false;
}

string User::getName()
{
    return name;
}

void User::addBike(Bike *bk)
{
    bike = bk;
    active = true;
}

void User::removeBike()
{
    active = false;
}

Member::Member(string username) : User(username)
{
    total_monthly_time = 0;
}

Regular::Regular(string username) : User(username) {}

double Regular::getPrice()
{

}
