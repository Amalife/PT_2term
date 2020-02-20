#include <iostream>
#include <cstring>

using namespace std;

const int   MAX_SPEED = 280;
const char*  COLOR = "blue";

class car
{
private:
    char    mark[10];
    char    color[15];
    int     speed;
    float   cost;
public:
    void    put_info()
    {
        cout << "Type car mark, color, max speed and cost\n";
        cin >> mark >> color >> speed >> cost;
    }
    void    get_info()
    {
        if (speed >= MAX_SPEED && !(strcmp(color, COLOR)))
        {
            cout << "\n Car mark is " << mark;
            cout << "\n Color is " << color;
            cout << "\n Max speed is " << speed;
            cout << "\n Cost is " << cost << endl;
        }
        else
            cout << "Car speed must be more than 280 km/h and car must have blue color\n";
    }
};

int main()
{
    car arg;

    arg.put_info();
    arg.get_info();
    return 0;
}

// Output:
/*
    Type car mark, color, max speed and cost
    Nissan blue 420 100000

     Car mark is Nissan
     Color is blue
     Max speed is 420
     Cost is 100000
*/