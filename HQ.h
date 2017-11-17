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
	void read_info(Date global_date); //Reads from file and fills the vectors
	void write_info();//Writes the data from the vectors to the text files
	void Main_Menu(Date global_date);
	void Bikes_Menu();
	void Station_Menu();
	void Payment_Menu(Date global_date);
	void Options_Menu(Date global_date);
	void Add_remove_member_menu();
	void Add_remove_station_menu();
	void RentBike();
	void Search_Station();
	void Nearest_Station();
	void Check_Balance(Date global_date);
	void Check_out(Date global_date);
    void addMember(); //Adds new member
	void removeMember();
    void addActiveUser(User *user); //Adds active user
    void addStation(); //Adds new station
	void removeStation();
	vector<User *> getActiveUsers() const;
	vector<Member *> getMembers() const;
	vector<Station *> getStations() const;
    int find_Member(string name); //Returns the index of the member in the HQ vector, else returns -1
    int find_ActiveUser(string name);  //Returns the index of the active user in the HQ vector, else returns -1
	int find_Station(string name); //Returns the index of the station in the HQ vector, else returns -1
	vector<Station *> find_bike_type(string type) const;
	void search_station(string name) const;
	void show_stations() const;
	void Reset_Members_MonthlyTime();
	void Rand_Localization();
	void FastForward_Time(int month, int day, int hour, int minute, Date global_date);
};

#endif