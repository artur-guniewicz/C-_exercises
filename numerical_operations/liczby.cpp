#include <iostream>

using namespace std;

int Suma(int t[])
{
    int i, S=0;

    for(i=0; i<10; i++)
    {
        S=S+t[i];
    }
    return S;
}

float Srednia(int N, int t[])
{
    float Sr;
    Sr = (float)Suma(t)/N;

    return Sr;
}

float Wariancja(int N, int t[])
{
    int i;
    float x=0, War;

    for(i=0; i<10 ;i++)
    {
        x = x + (t[i]-Srednia(N, t))*(t[i]-Srednia(N, t));
    }

    War = x/N;

    return War;
}

int NWD(int a, int b)
{
    int c;

    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int NWDt(int t[], int n)
{
    int i, Nwdt = t[0];

    for(i=1; i<n; i++)
        Nwdt = NWD(Nwdt, t[i]);

    return Nwdt;
}

int NWW(int a, int b)
{
    int Nww = 0;

    Nww = (a*b)/NWD(a, b);

    return Nww;
}

int NWWt(int t[], int n)
{
    int i, Nwwt = t[0];

    for(i=1; i<n; i++)
        Nwwt = NWW(Nwwt, t[i]);

    return Nwwt;
}

int main()
{
    int i, N, tab[10];

    N = sizeof(tab)/sizeof(tab[0]);
    cout << "Rozmiar tablicy: " << N << endl;

    cout << "Podaj 10 liczb całkowitych (oddzielone enterem)" << endl;

    for(i=0; i<10; i++)
    {
        cin >> tab[i];
    }

    cout << "Podane przez ciebie liczby to: ";
    for(i=0; i<10; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;

    cout << "Suma: " << Suma(tab) << endl;
    cout << "Średnia: " << Srednia(N, tab) << endl;
    cout << "Wariancja: " << Wariancja(N, tab) << endl;
    cout << "NWD: " << NWDt(tab, N) << endl;
    cout << "NWW: " << NWWt(tab, N) << endl;



    return 0;
}