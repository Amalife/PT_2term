Тема:  Объектно-ориентированное программирование на С++
 Классы в С++

/*Пример 1. Описать класс car, который содержит поля для  описания марки, цвета и стоимости автомобиля и функции для ввода этих 
значений (getinfo()) и вывода на экран (putinfo()).
//////////////////////////////////////////////*/
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
////////////////////////////////////////////////////////////////
/*Пример 2. Описать класс coord с полями х, у и функциями putinfo(col,row) для инициализации полей класса x,y и 
void getinfo(int _x,int _y) для инициализации простых переменных значениями полей класса coord.  
Объявить объект класса arg. Показать обращение к методам класса из функции void main() c помощью указателя на класс.
//////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

class   coord
{
private:
    int c_x, c_y;
public:
    void getinfo(int x, int y)
    {
        c_x = x;
        c_y = y;
    }
    void putinfo(int &x, int &y)
    {
        x = c_x;
        y = c_y;
        cout << "x = " << c_x << endl << "y = " << c_y << endl;
    }
};

int     main()
{
    coord   arg;
    coord   *p = &arg;

    arg.getinfo(10, 5);
    int     col, row;
    p->putinfo(col, row);
    return 0;
}

// Output:
/*
    x = 10
    y = 5
*/
/////////////////////////////////////////////////////////////////
/*Пример 3. Описать класс автомобилей с полями: марка, цвет, развиваемая скорость, цена. 	Вывести на экран данные об автомобиле, 
если его развиваемая скорость не меньше заданной и заданного цвета.
///////////////////////////////////////////////////////////////*/
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
///////////////////////////////////////////////////////////////////
/*Пример 4. Определить класс вектор. Предусмотреть три функции-члены:
a)	для ввода элементов одномерного массива;
b)	для обработки массива с целью получения суммы отрицательных элементов;
c)	для вывода  результата.
/////////////////////////////////////////////////////////////////*/
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
///////////////////////////////////////////////////////////////
