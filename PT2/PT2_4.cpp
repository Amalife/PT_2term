#include <iostream>
#include <cmath>

using namespace std;

float s(float x, float y, float z)
{
    return 2 * (x * y + y * z + x * z);
}

float s(float r, float h)
{
    return 2 * M_PI * r * h + M_PI * r * r;
}

float s(float r)
{
    return 4 * M_PI * r;
}

int main()
{
    float a_par, a_cyl, a_sp;

    a_par = s(2.5, 3, 8.1);
    a_cyl = s(2.7, 2.3);
    a_sp = s(4.6);
    cout << "parallelepiped area is " << a_par << "; cylinder area is " << a_cyl << "; sphere area is " << a_sp << endl;
    return 0;
}

// Output:
/*
    parallelepiped area is 104.1; cylinder area is 61.9208; sphere area is 57.8053
*/