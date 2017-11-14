#ifndef AEDA_P1_FUNCS_H
#define AEDA_P1_FUNCS_H

#include <iostream>
#include <vector>
#include <string>
#include "HQ.h"

using namespace std;

void Main_Menu(HQ hq);
void Bikes_Menu(HQ hq);
void Station_Menu(HQ hq);
void Payment_Menu();
void InvalidInput(int n_op, int &op);
void RentBike(HQ hq);
void Search_Station(HQ hq);
double calc_distance(int x1, int y1, int x2, int y2);
void Nearest_Station(HQ hq);
#endif