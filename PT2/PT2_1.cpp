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