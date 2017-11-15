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
	Date g_date(11, 15, 15, 11);

	hq.read_info(g_date);
	hq.Main_Menu(g_date);

    return 0;
}