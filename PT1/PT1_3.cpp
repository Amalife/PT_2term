#include <iostream>

using namespace std;

void    scholarship(const char *name, int low_mark = 4, int grant = 1000)
{
    if (low_mark > 3 && low_mark < 6)
        cout << name << " earned " << low_mark * grant << " rubbles, having " << low_mark << " low mark\n";
    else
        cout << name << " has no scholarship\n";
}

int     main()
{
    scholarship("Petrov");
    scholarship("Ivanov", 3);
    scholarship("Sidorov", 5);
    return 0;
}