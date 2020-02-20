#include <iostream>

using namespace std;

class car
{
private:
    char    mark[10];
    char    color[15];
    float   cost;
public:
    void    get_info();
    void    put_info()
    {
        cout << "\n Car mark is " << mark;
        cout << "\n Color is " << color;
        cout << "\n Cost is " << cost << endl;
    }
};

void    car::get_info()
{
    cout << "Type car mark, color and cost\n";
    cin >> mark >> color >> cost;
}

int     main()
{
    car arg;
    
    arg.get_info();
    arg.put_info();
    return 0;
}

// Output:
/*
    Type car mark, color and cost
    Dodge red 30000

     Car mark is Dodge
     Color is red
     Cost is 30000
*/