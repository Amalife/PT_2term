#include <iostream>
#include <cmath>

using namespace std;

float v (float r);
float v (float x, float y, float z);
float v(float r, float h);

int main()
{
    float v_sf, v_cil, v_par;

    v_sf = v(2.5);
    v_cil = v(3, 4.5);
    v_par = v(2, 4, 0.7);
    cout << "sphere volume is " << v_sf << "; cylinder volume is " << v_cil << "; parallelepiped volume is " << v_par << endl;
}

float v(float r)
{
    return 4 * M_PI * pow(r,3)/3;
}

float v(float r, float h)
{
    return M_PI * r * r * h;
}

float v(float x, float y, float z)
{
    return x * y * z;
}