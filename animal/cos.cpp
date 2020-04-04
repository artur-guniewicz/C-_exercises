#include <iostream>
#include <string>
#include "cos.h"

using namespace std;


void Zwierze::dodaj()
{
    cout << "DODAWANIE NOWEGO ZWIERZA" << endl;

    cout << "Podaj nazwę: ";
    cin >> _nazwa;
    cout << "Podaj ilość: ";
    cin >> _ilosc;
}

void Zwierze::wypisz()
{
    cout << _nazwa << " " << _ilosc << endl;
}