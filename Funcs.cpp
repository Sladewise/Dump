#include "Funcs.h"

using namespace std;

void Main_Menu()
{
    int opt;

    do
    {
        cout << "+-------------+--------------+\n"
             << "| 1 - Bikes   | 2 - Stations |\n"
             << "+-------------+--------------+\n"
             << "| 3 - Payment | 4 - Options  |\n"
             << "+-------------+--------------+\n"
             << "|      5 - Save and Exit     |\n"
             << "+----------------------------+\n";

        cin >> opt;

        InvalidInput(2, opt);

        switch(opt)
        {
            case 1:
                Bikes_Menu();
                break;

            case 2:
                Station_Menu();
                break;

            case 3:

                break;

            case 4:

                break;

            case 5:
                break;

            default:
                break;
        }

    }while(opt != 5);
}

void Bikes_Menu()
{
    int opt;

    do
    {
        cout << "+---------------+\n"
             << "| 1 - Rent bike |\n"
             << "+---------------+\n"
             << "|  2 - Go back  |\n"
             << "+---------------+\n";

        cin >> opt;

        InvalidInput(2, opt);

        switch(opt)
        {
            case 1:

                break;

            case 2:
                break;

            default:
                break;
        }
    }while(opt != 2);
}

void Station_Menu()
{
    int opt;
    do
    {
        cout << "+--------------------------+-------------------+\n"
             << "| 1 - Search station       | 2 - Show stations |\n"
             << "+--------------------------+-------------------+\n"
             << "| 3 - Show nearest station | 4 - Go back       |\n"
             << "+--------------------------+-------------------+\n";

        cin >> opt;

        InvalidInput(4, opt);

        switch(opt)
        {
            case 1:

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:
                break;

            default:
                break;
        }
    }while(opt != 4);
}

void Payment_Menu()
{
    int opt;

    do
    {
        cout << "+-------------------+\n"
             << "| 1 - Balance       |\n"
             << "+-------------------+\n"
             << "| 2 - Checkout bike |\n"
             << "+-------------------+\n"
             << "| 3 - Go back       |\n"
             << "+-------------------+\n";

        cin >> opt;

        InvalidInput(3, opt);

        switch(opt)
        {
            case 1:

                break;

            case 2:

                break;

            default:
                break;
        }
    }while(opt != 3);
}

void InvalidInput(int n_op, int &op)
{
    while(cin.fail() || (op < 1 && op > n_op))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Invalid option! Please try again\n" << endl;
        cin >> op;
    }
}