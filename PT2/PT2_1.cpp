Тема: Отличие С++ от Си (ссылки в С++ и перегруженные функции).

/*Пример 1
Пусть для одномерных массивов Х[], Y[], Z[] с разным количеством элементов необходимо вычислить отдельно сумму отрицательных элементов, 
сумму положительных элементов и количество нулевых.
Кроме функции main( ), предусмотрим функцию vvod( ) для ввода элементов одного одномерного массива и 
функцию вычисления требуемых результатов для переданного в функцию массива. Последнюю сделаем в двух вариантах:
fukaz( ) – передача результатов с помощью указателей;
fssilka( ) – передача результатов с использованием ссылок.
/////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

const int Nx = 10;

void    vvod (float x[], int n, char q);
void    fukaz(float x[], int n, float *sum_otr, int *kol_O, float *sum_pol);
void    fssilka(float x[], int n, float &sum_otr, int &kol_O, float &sum_pol);

int     main( )
{

    float x[Nx], s_p, s_o;
    int k_nul;

    vvod (x, Nx, 'x');
    fukaz (x, Nx, &s_o, &k_nul, &s_p);
    cout << "Pointer: sum of negatives = " << s_o << "; the number of zeros = " << k_nul << "; sum of positives = " << s_p << endl;
    fssilka(x, Nx, s_o, k_nul, s_p);
    cout << "Link: sum of negatives = " << s_o << "; the number of zeros = " << k_nul << "; sum of positives = " << s_p << endl;
    return 0;
}

void vvod(float x[], int n, char q)
{
    for (int i=0; i < n; i++)
    {  
        cout << "type " << q << "[" << i << "] = ";
        cin >> x[i];
        cout << endl;
    }
}

void fukaz(float x[], int n, float *sum_otr, int *kol_O, float *sum_pol)
{
    *sum_otr = 0;    
    *kol_O = 0;   
    *sum_pol = 0;
    for (int i=0; i < n; i++)
        if (x[i] < 0)   
            *sum_otr += x[i];
        else if (x[i] > 0)
            *sum_pol += x[i];
        else   
            *kol_O += 1;
}
void fssilka (float x[],int n, float &sum_otr, int &kol_O, float &sum_pol)
{
    sum_otr=kol_O=sum_pol=0;
    for (int i= 0; i < n; i++)
        if(x[i] < 0)   
            sum_otr += x[i];
        else if (x[i] > 0)
            sum_pol += x[i];
        else    
            kol_O++;
}

// Output:
/*
    type x[0] = 1
    type x[1] = 2
    type x[2] = 0
    type x[3] = -1
    type x[4] = -2
    type x[5] = 0
    type x[6] = 3
    type x[7] = 4
    type x[8] = 0
    type x[9] = -3

    Pointer: sum of negatives = -6; the number of zeros = 3; sum of positives = 10
    Link: sum of negatives = -6; the number of zeros = 3; sum of positives = 10
*/
///////////////////////////////////////////////////////////////////////////////////
/*Пример 2
Для кaждого из трёх одномерных мaccивов нaйти нaибольший, нaименьший элементы и их номерa. В программе предуcмотреть отдельную функцию, 
в которой вычисляются все необходимые значения для одного массива и возвращаются с помощью ссылок. 
Для cрaвнения cоздaть еще одну функцию, которaя делaет то же caмое, что и первaя, но дaнные получaет c помощью укaзaтелей.
/////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

const int Nx = 10;

void    vvod (float x[], int n, char q);
void    fukaz(float x[], int n, float *max_el, float *min_el, int *max_num, int *min_num);
void    fssilka(float x[], int n, float &max_el, float &min_el, int &max_num, int &min_num);

int     main()
{

    float   x[Nx], max_el, min_el;
    int     max_num, min_num;

    vvod (x, Nx, 'x');
    fukaz (x, Nx, &max_el, &min_el, &max_num, &min_num);
    cout << "Pointer: max element x[" << max_num << "] = " << max_el << "; min element x[" << min_num << "] = " << min_el << endl;
    fssilka(x, Nx, max_el, min_el, max_num, min_num);
    cout << "Link: max element x[" << max_num << "] = " << max_el << "; min element x[" << min_num << "] = " << min_el << endl;
    return 0;
}

void vvod(float x[], int n, char q)
{
    for (int i=0; i < n; i++)
    {  
        cout << "type " << q << "[" << i << "] = ";
        cin >> x[i];
        cout << endl;
    }
}

void fukaz(float x[], int n, float *max_el, float *min_el, int *max_num, int *min_num)
{
    *max_num = 0;
    *min_num = 0;
    *max_el = 0;    
    *min_el = 0;
    for (int i=0; i < n; i++)
        if (x[i] < *min_el)
        {
            *min_el = x[i];
            *min_num = i;
        }
        else if (x[i] > *max_el)
        {
            *max_el = x[i];
            *max_num = i;
        }
}
void fssilka (float x[],int n, float &max_el, float &min_el, int &max_num, int &min_num)
{
    max_el = min_el = max_num = min_num = 0;
    for (int i=0; i < n; i++)
        if (x[i] < min_el)   
        {
            min_el = x[i];
            min_num = i;
        }
        else if (x[i] > max_el)
        {
            max_el = x[i];
            max_num = i;
        }
}

// Output:
/*
    type x[0] = 1
    type x[1] = 2
    type x[2] = 0
    type x[3] = -1
    type x[4] = -2
    type x[5] = 0
    type x[6] = 3
    type x[7] = 4
    type x[8] = -3
    type x[9] = -4
    Pointer: max element x[7] = 4; min element x[9] = -4
    Link: max element x[7] = 4; min element x[9] = -4
*/
////////////////////////////////////////////////////////////////////////
/*Пример 3
Вычислить объем сферы (V=4/3πR3), параллелепипеда (V=xyz) и цилиндра (V=πR2h). Показать в программе перегруженные функции.
///////////////////////////////////////////////////////////////////////*/
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

// Output:
/*
    sphere volume is 65.4498; cylinder volume is 127.235; parallelepiped volume is 5.6
*/
/////////////////////////////////////////////////////////////////////////////////////////
/*Пример 4.
Состaвить нa языке С++ прогрaмму для вычисления площaди поверхности пaрaллелепипедa, 
цилиндрa (Sосн.=πr2   Sбок. = 2πrh) и сферы (S=4 π R2).
Предусмотреть отдельные функции для вычисления поверхности любой из фигур. Все функции для вычисления поверхности обозначить через S. 
///////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <cmath>

using namespace std;

float s(float x, float y, float z)
{
    return 2 * (x * y + y * z + x * z);
}

float s(float r, float h)
{
    return 2 * M_PI * r * h + M_PI * r * r;
}

float s(float r)
{
    return 4 * M_PI * r;
}

int main()
{
    float a_par, a_cyl, a_sp;

    a_par = s(2.5, 3, 8.1);
    a_cyl = s(2.7, 2.3);
    a_sp = s(4.6);
    cout << "parallelepiped area is " << a_par << "; cylinder area is " << a_cyl << "; sphere area is " << a_sp << endl;
    return 0;
}

// Output:
/*
    parallelepiped area is 104.1; cylinder area is 61.9208; sphere area is 57.8053
*/
/////////////////////////////////////////////////////////////////////////////////////
