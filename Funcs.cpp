#include "Funcs.h"

using namespace std;

void InvalidInput(int n_op, int &op)
{
    while(cin.fail() || (op < 1 || op > n_op))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Invalid option! Please try again\n" << endl;
        cin >> op;
    }
}

double calc_distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

/*just a comment to test commit -> Pitty */











