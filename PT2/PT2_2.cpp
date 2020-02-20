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