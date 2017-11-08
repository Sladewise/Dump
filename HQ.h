#ifndef P1_HQ_H
#define P1_HQ_H

#include "User.h"
#include "Station.h"

using namespace std;

class HQ
{
    vector<Member *> members;
    vector<User *> active_users;
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

#endif //P1_HQ_H
