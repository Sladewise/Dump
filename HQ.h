#ifndef AEDA_P1_HQ_H
#define AEDA_P1_HQ_H

#include "User.h"
#include "Station.h"
#include <time.h>

using namespace std;

class HQ
{
    vector<Member *> members;
    vector<User *> active_users;
    vector<Station *> stations;

public:
    HQ();
    void read_info() const;  //Reads from file and fills the vectors
    void write_info() const; //Writes the data from the vectors to the text files
    void addMember(Member member); //Adds new member
    void addActiveUser(User *user); //Adds active user
    void addStation(Station station); //Adds new station
	vector<User *> getActiveUsers() const;
	vector<Member *> getMembers() const;
	vector<Station *> getStations() const;
    int find_Member(string name); //Returns a pointer to the Member if it exists, else a pointer to a "null member"
    int find_ActiveUser(string name);  //Returns a pointer to an active user if it exists, else returns a pointer to a "null active user"
	vector<Station *> find_bike_type(string type) const;
	void search_station(string name) const;
};

#endif