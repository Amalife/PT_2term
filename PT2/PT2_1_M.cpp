#include <iostream>

using namespace std;

const int Nx = 3;

void    vvod (float x[Nx][Nx], int n, char q);
void    fukaz(float x[Nx][Nx], int n, float *sum_otr, int *kol_O, float *sum_pol);
void    fssilka(float x[Nx][Nx], int n, float &sum_otr, int &kol_O, float &sum_pol);

int     main( )
{

    float x[Nx][Nx], s_p, s_o;
    int k_nul;

    vvod (x, Nx, 'x');
    fukaz (x, Nx, &s_o, &k_nul, &s_p);
    cout << "Pointer: sum of negatives = " << s_o << "; the number of zeros = " << k_nul << "; sum of positives = " << s_p << endl;
    fssilka(x, Nx, s_o, k_nul, s_p);
    cout << "Link: sum of negatives = " << s_o << "; the number of zeros = " << k_nul << "; sum of positives = " << s_p << endl;
    return 0;
}

void vvod(float x[Nx][Nx], int n, char q)
{
    for (int j = 0; j < n; j++)
        for (int i=0; i < n; i++)
        {  
            cout << "type " << q << "[" << j << "]" << "[" << i << "] = ";
            cin >> x[j][i];
            cout << endl;
        }
}

void fukaz(float x[Nx][Nx], int n, float *sum_otr, int *kol_O, float *sum_pol)
{
    *sum_otr = 0;    
    *kol_O = 0;   
    *sum_pol = 0;
    for (int j = 0; j < n; j++)
        for (int i=0; i < n; i++)
            if (x[j][i] < 0)   
                *sum_otr += x[j][i];
            else if (x[j][i] > 0)
                *sum_pol += x[j][i];
            else   
                *kol_O += 1;
}
void fssilka (float x[Nx][Nx],int n, float &sum_otr, int &kol_O, float &sum_pol)
{
    sum_otr=kol_O=sum_pol=0;
    for (int j = 0; j < n; j++)
        for (int i= 0; i < n; i++)
            if(x[j][i] < 0)   
                sum_otr += x[j][i];
            else if (x[j][i] > 0)
                sum_pol += x[j][i];
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