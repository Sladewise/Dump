//Classes

#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

class HQ
{
    vector<Member> members;
    vector<User> active_users;
    vector<Station> stations;

public:
    HQ();
    void read_info() const;  //Reads from file and fills the vectors
    void write_info() const; //Writes the data from the vectors to the text files
    void addMember(Member member); //Adds new member
    void addActiveUser(User user); //Adds active user;
    void addStation(Station station); //Adds new station
    int find_Member(Member member); //Returns the index of a Member if it exists, else returns -1;
    int find_ActiveUser(User active_user);  //Returns the index of an active user if it exists, else returns -1;
};

//Bike

class Bike
{
    string ID;
    time_t time_start;

public:

    virtual double getPrice();
};

class Urban_b: public Bike
{
    double price_hour;

public:
    double getPrice();
};

class Urban_simple_b: public Bike
{
    double price_h;

public:
    double getPrice();
};

class Race_b: public Bike
{
    double price_h;

public:
    double getPrice();
};

class Child_b: public Bike
{
    double price_h;

public:
    double getPrice();
};

class Station
{
    int no_max_spots;
    string position;
    vector<Bike> available_bikes;

public:
    Station(int max_spots, string localization);
    void Menu();
    Bike findBike(string bike_id);
};

//User

class User
{
    bool active;
    Bike bike;
    string name;

public:
    User(string username);
    string getName();
    Station getClosestStation(); //Args still need to be discussed
    void addBike(Bike bk);
    void removeBike();
};

class Member: public User
{
    int total_monthly_time;
    static double price_month;

public:
    Member(string username);
    double getPrice();

};

class Regular: public User
{
    static double price_hour;
public:
    Regular(string username);
    double getPrice();
};

