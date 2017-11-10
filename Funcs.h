#ifndef AEDA_P1_FUNCS_H
#define AEDA_P1_FUNCS_H

#include <iostream>
#include <vector>
#include <string>
#include "HQ.h"

using namespace std;

void Main_Menu();
void Bikes_Menu();
void Station_Menu();
void InvalidInput(int n_op, int &op);
void RentBike(HQ hq);

#endif