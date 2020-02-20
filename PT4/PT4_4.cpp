#include <iostream>

using namespace std;

const int   D = 2;

class vector
{
private:
    float     c_x[D];
    float     sum = 0;
public:
    void    input()
    {
        for (int i = 0; i < D; i++)
        {
            cout << "type x[" << i << "] = ";
            cin >> c_x[i];
            cout << endl;
        }
    }
    void    sum_neg()
    {
        for (int i = 0; i < D; i++)
        {
            if (c_x[i] < 0)
                sum += c_x[i];
        }
    }
    void    output()
    {
        cout << "Sum of negative elements of the vector is " << sum << endl;
    }
};

int main()
{
    vector arg;

    arg.input();
    arg.sum_neg();
    arg.output();
    return 0;
}

// Output:
/*
    type x[0] = -2
    type x[1] = -3
    
    Sum of negative elements of the vector is -5
*/