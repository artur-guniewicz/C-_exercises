#include <iostream>

using namespace std;

class Punkt
{
public:
    Punkt() : x(0), y(0) {}
    Punkt(double _x, double _y) : x(_x), y(_y) {}
    double x, y;
};

Punkt operator+(const Punkt &a, const Punkt &b)
{
    return Punkt(a.x + b.x, a.y + b.y);
}

Punkt operator-(const Punkt &a, const Punkt &b)
{
    return Punkt(a.x - b.x, a.y - b.y);
}

ostream & operator<<(ostream &wyjscie, const Punkt &pkt)
{
    return wyjscie << "Przebudowany operator << : " << "x = " << pkt.x << "  " << "y = " << pkt.y << endl;
}

void wypisz(Punkt &pkt)
{
    cout << "x = " << pkt.x << "  " << "y = " << pkt.y << endl;
}

int main()
{
    Punkt a(3,1);
    Punkt b(2,3);
    Punkt wynik;
    cout << "Punkt a:       "; wypisz(a);
    cout << "Punkt b:       "; wypisz(b);

    wynik = operator+(a, b);
    cout << "Punkt a+b:     "; wypisz(wynik);

    wynik = operator-(a, b);
    cout << "Punkt a-b:     "; wypisz(wynik);

    cout << a;
}