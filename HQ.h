#ifndef AEDA_P1_HQ_H
#define AEDA_P1_HQ_H

#include "User.h"
#include "Station.h"
#include "Funcs.h"
#include <time.h>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class HQ
{
    vector<Member *> members;
    vector<User *> active_users;
    vector<Station *> stations;

public:
    HQ();
	void read_info(Date global_date); //Reads from file and fills the vectors
	void write_info() const; //Writes the data from the vectors to the text files
	void Main_Menu(Date &global_date); //Main user interface
	void Bikes_Menu(); //Interface related to the Bikes
	void Station_Menu(); //Interface related to the Stations
	void Payment_Menu(Date global_date); //Interface related to the payment options
	void Options_Menu(Date &global_date); //Interface with several options for testing purposes
	void Add_remove_member_menu(); //Interface regarding the addition or removal of members
	void Add_remove_station_menu(); //Interface regarding the addition or removal of stations
	void RentBike(); //Initiates the renting process of a bike
	void Search_Station(); //Searches for a particular station and, if found, returns information about it
	void Nearest_Station(); //Returns information about the closest station to the user
	void Check_Balance(Date global_date); //Shows how much a regular active user has to pay so far or how much a member has to pay at the end of the month
	void Check_out(Date global_date); //Initiates the process of returning a bike and payment(if necessary)
    void addMember(); //Adds a new member
	void removeMember(); //Removes an existing member
    void addActiveUser(User *user); //Adds an active user
    void addStation(); //Adds a new station
	void removeStation(); //Removes an existing station
	vector<User *> getActiveUsers() const; //Returns the active users vector
	vector<Member *> getMembers() const; //Returns the members vector
	vector<Station *> getStations() const; //Returns the stations vector
    int find_Member(string name); //Returns the index of the member in the HQ vector, else returns -1
    int find_ActiveUser(string name);  //Returns the index of the active user in the HQ vector, else returns -1
	int find_Station(string name); //Returns the index of the station in the HQ vector, else returns -1
	vector<Station *> find_bike_type(string type) const;
	void search_station(string name) const;
	void show_stations() const;
	void Reset_Members_MonthlyTime();
	void Rand_Localization();
	void FastForward_Time(int month, int day, int hour, int minute, Date &global_date);
};

#endif