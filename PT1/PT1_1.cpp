#include <iostream>

using namespace std;

void    zarplata(const char *s, int days = 24, float rascenka = 30.5);

int     main()
{
    zarplata("man");
    zarplata("brother", 26);
    zarplata("sister", 24, 41);
    return 0;
}

void    zarplata(const char *s, int days, float rascenka)
{
    cout << s << " earned " << days * rascenka << " dollars\n";
}