#include <iostream>

using namespace std;

class   coord
{
private:
    int c_x, c_y;
public:
    void getinfo(int x, int y)
    {
        c_x = x;
        c_y = y;
    }
    void putinfo(int &x, int &y)
    {
        x = c_x;
        y = c_y;
        cout << "x = " << c_x << endl << "y = " << c_y << endl;
    }
};

int     main()
{
    coord   arg;
    coord   *p = &arg;

    arg.getinfo(10, 5);
    int     col, row;
    p->putinfo(col, row);
    return 0;
}

// Output:
/*
    x = 10
    y = 5
*/