#include <iostream>

using namespace std;

inline float min(float a, float b)
{
    return a < b ? a : b;
}

int main()
{
    float x, y, v;

    cout << "Type x and y\n";
    cin >> x >> y;
    v = min(x, y);
    cout << v << endl;
    return 0;
}

// Output:
/*
    Type x and y
    -1 3
    -1
*/