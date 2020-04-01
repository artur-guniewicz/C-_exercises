#include <iostream>
#include <math.h>

using namespace std;


class FunkcjaKwadratowa
{
    public:
        void wprowadzDane();
        void wypiszDane();
        void wynik();
        void wartosc_w_punkcie();

    private:
        float a, b, c;
};

void FunkcjaKwadratowa::wprowadzDane()
{
    cout << "Podaj a: ";
    cin >> a;
    cout << "Podaj b: ";
    cin >> b;
    cout << "Podaj c: ";
    cin >> c;
}

void FunkcjaKwadratowa::wypiszDane()
{
    cout << "f(x) = " << a << " x^2 + " << b << " x + " << c <<endl;
}

void FunkcjaKwadratowa::wynik()
{
    float x, x0, x1, x2, delta;

    if(a==0)
    {
        if(b==0)
        {
            if(c==0)
            {
                cout << "Funkcja ma nieskończenie wiele rozwiązań" << endl;
            }
            else
            {
                cout << "Funkcja nie ma rozwiązań" << endl;
            }
        }
        else
        {
            x = (-c)/b;
            cout << "Funkcja liniowa, ma jedno rozwiązanie x = " << x << endl;
        }
    }
    else
    {
        delta = (b*b)-(4*a*c);
        x0 = -b/(2*a);
        x1 = (-b-sqrt(delta))/(2*a);
        x2 = (-b+sqrt(delta))/(2*a);

        if(delta<0) cout << "Funkcja nie ma rozwiązań" <<endl;
        else if(delta==0) cout << "Funkcja ma jedno rozwiązanie x0 = " << x0 << endl;
        else cout << "Funkcja ma dwa rozwiązania x1 = " << x1 << " i x2 = " << x2 << endl;
    }
}

void FunkcjaKwadratowa::wartosc_w_punkcie()
{
    float x, y;

    cout << "Podaj punkt x: ";
    cin >> x;

    y = (a*x*x)+(b*x)+c;

    cout << "f(" << x << ") = " << y << endl;
}

int main()
{
    FunkcjaKwadratowa funkcja;

    funkcja.wprowadzDane();
    funkcja.wypiszDane();
    funkcja.wynik();
    funkcja.wartosc_w_punkcie();


    return 0;
}