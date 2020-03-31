#include <iostream>
#include <string>
#include "dane.h"

using namespace std;

void wypiszDane(Pracownik pracownik1);

void wprowadzDane(Pracownik pracownik1)
{
    string imie, nazwisko, ulica, dom, kod, miejscowosc;

    cout << "UZUPEŁNIJ DANE PRACOWNIKA\n" << endl;

    cout << "Imię: \n\t";
    getline(cin, imie);
    pracownik1.setImie(imie);
    cout << endl;

    cout << "Nazwisko: \n\t";
    getline(cin, nazwisko);
    pracownik1.setNazwisko(nazwisko);
    cout << endl;

    cout << "Ulica: \n\t";
    getline(cin, ulica);
    pracownik1.setUlica(ulica);
    cout << endl;

    cout << "Numer domu: \n\t";
    getline(cin, dom);
    pracownik1.setDom(dom);
    cout << endl;

    cout << "Kod pocztowy: \n\t";
    getline(cin, kod);
    pracownik1.setKod(kod);
    cout << endl;

    cout << "Mijescowość: \n\t";
    getline(cin, miejscowosc);
    pracownik1.setMiejscowosc(miejscowosc);
    cout << endl;

    wypiszDane(pracownik1);
}

void wypiszDane(Pracownik pracownik1)
{
    cout << "-----------------------------\n"
         << pracownik1.getImie() << " " << pracownik1.getNazwisko() << endl
         << "ul. " << pracownik1.getUlica() << " " << pracownik1.getDom() << endl
         << pracownik1.getKod() << " " << pracownik1.getMiejscowosc() << endl
         << "-----------------------------\n";
}

int main()
{
    Pracownik pracownik1;

    wprowadzDane(pracownik1);

    return 0;
}