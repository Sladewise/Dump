#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "HQ.h"
#include "Funcs.h"

using namespace std;

int main()
{
	HQ hq;
	hq.read_info();
	Main_Menu(hq);

    return 0;
}