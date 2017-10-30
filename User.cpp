#include "User.h"
#include <iostream>
#include "Bike.h"

using namespace std;

User::User(string username)
{
    name = username;
    active = false;
}

string User::getName()
{
    return name;
}

void User::addBike(Bike bk)
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
