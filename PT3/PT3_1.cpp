Тема:          Отличия С++ от С
Операция разрешения видимости
Встроенные (inline) функции
Функция main()
Гибкие операторы динамического распределения памяти: new, delete
Константные значения

//Пример 1
///////////////////////////////////////////////////
#include <iostream>

using namespace std;

double x = 10;

int main()
{
    double x = 100;

    cout << "Global variable x = " << ::x << endl;
    cout << "Local variable x = " << x << endl;
    for (int i = 0; i < 2; i++)
    {
        double x = 1000;
        cout << "Inside block x = " << x << endl;
    }
    return 0;
}

// Output:
/*
    Global variable x = 10
    Local variable x = 100
    Inside block x = 1000
    Inside block x = 1000
*/
//////////////////////////////////////////////////////////
//Пример 2.
//////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////
