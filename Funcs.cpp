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

void fast_forward_menu(HQ hq, Date &global_date)
{
	int opt, n_min, n_hr, n_d, n_mt;

	cout << "+-------------------+\n"
		<< "| 1 - Add minute(s) |\n"
		<< "+-------------------+\n"
		<< "| 2 - Add hour(s)   |\n"
		<< "+-------------------+\n"
		<< "| 3 - Add day(s)    |\n"
		<< "+-------------------+\n"
		<< "| 4 - Add month(s)  |\n"
		<< "+-------------------+\n" << endl;

	cin >> opt;

	InvalidInput(4, opt);

	switch (opt)
	{
		case 1:
			cout << "Number of minutes: ";
			cin >> n_min;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Input. Please try again.\n";
				cin >> n_min;
			}

			hq.FastForward_Time(0, 0, 0, n_min, global_date);
			break;

		case 2:
			cout << "Number of minutes: ";
			cin >> n_hr;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Input. Please try again.\n";
				cin >> n_hr;
			}

			hq.FastForward_Time(0, 0, n_hr, 0, global_date);
			break;

		case 3:
			cout << "Number of minutes: ";
			cin >> n_d;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Input. Please try again.\n";
				cin >> n_d;
			}

			hq.FastForward_Time(0, n_d, 0, 0, global_date);
			break;

		case 4:
			cout << "Number of minutes: ";
			cin >> n_mt;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Input. Please try again.\n";
				cin >> n_mt;
			}

			hq.FastForward_Time(n_mt, 0, 0, 0, global_date);
			break;
	}
}

Date read_date()
{
	ifstream read;
	istringstream sstr;
	string date, interval;
	int min, hr, d, mt;

	read.open("Date.txt");
	getline(read, date);
	read.close();

	sstr.str(date);
	sstr >> d >> interval >> mt >> interval >> hr >> interval >> min;

	Date global_date(mt, d, hr, min);

	return global_date;
}

void write_date(Date global_date)
{
	ofstream write;

	write.open("Date.txt");

	write << global_date.getDay() << " / " << global_date.getMonth() << " ; "
		<< global_date.getHour() << " : " << global_date.getMinutes();

	write.close();
}










