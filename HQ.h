#ifndef AEDA_P1_HQ_H
#define AEDA_P1_HQ_H

#include "User.h"
#include "Station.h"
#include "Funcs.h"
#include <time.h>
#include <fstream>
#include <sstream>

using namespace std;

class HQ
{
    vector<Member *> members;
    vector<User *> active_users;
    vector<Station *> stations;

public:
    HQ();
	void read_info(); //Reads from file and fills the vectors
	void write_info();//Writes the data from the vectors to the text files
	void Main_Menu();
	void Bikes_Menu();
	void Station_Menu();
	void Payment_Menu(Date g_date);
	void RentBike();
	void Search_Station();
	void Nearest_Station();
	void Check_Balance();
	void Check_out(Date g_date);
    void addMember(Member member); //Adds new member
    void addActiveUser(User *user); //Adds active user
    void addStation(Station *station); //Adds new station
	vector<User *> getActiveUsers() const;
	vector<Member *> getMembers() const;
	vector<Station *> getStations() const;
    int find_Member(string name); //Returns the index of the member in the HQ vector, else returns -1
    int find_ActiveUser(string name);  //Returns the index of the active user in the HQ vector, else returns -1
	vector<Station *> find_bike_type(string type) const;
	void search_station(string name) const;
	void show_stations() const;
};

#endif