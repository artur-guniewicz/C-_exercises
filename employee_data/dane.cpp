#include <iostream>
#include <string>
#include "dane.h"

using namespace std;

string _imie, _nazwisko, _ulica, _dom, _kod, _miejscowosc;

void Pracownik::setImie(string imie)
{
    _imie = imie;
}

void Pracownik::setNazwisko(string nazwisko)
{
    _nazwisko = nazwisko;
}

void Pracownik::setUlica(string ulica)
{
    _ulica = ulica;
}

void Pracownik::setDom(string dom)
{
    _dom = dom;
}

void Pracownik::setKod(string kod)
{
    _kod = kod;
}

void Pracownik::setMiejscowosc(string miejscowosc)
{
    _miejscowosc = miejscowosc;
}

string Pracownik::getImie()
{
    return _imie;
}

string Pracownik::getNazwisko()
{
    return _nazwisko;
}

string Pracownik::getUlica()
{
    return _ulica;
}

string Pracownik::getDom()
{
    return _dom;
}

string Pracownik::getKod()
{
    return _kod;
}

string Pracownik::getMiejscowosc()
{
    return _miejscowosc;
}