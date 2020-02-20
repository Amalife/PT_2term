#include <iostream>

using namespace std;

double x = 10;

int main()
{
    double x = 100;

    cout << "Global variable x = " << ::x << endl;
    cout << "Local variable x = " << x << endl;
    for (int i = 0; i < 2; i++)
    {
        double x = 1000;
        cout << "Inside block x = " << x << endl;
    }
    return 0;
}

// Output:
/*
    Global variable x = 10
    Local variable x = 100
    Inside block x = 1000
    Inside block x = 1000
*/