#include <iostream>

const int SD_YES = 2;
const int SD_NO = 1;

using namespace std;

void    salary(const char *name, int deg, int days = 25, float rate = 30.6)
{
    cout << name << " earned " << rate * deg * days << " dollars\n";
}

int     main()
{
    salary("Newton", SD_YES);
    salary("Raskolnikov", SD_NO);
    salary("Einstein", SD_YES);
    return 0;
}