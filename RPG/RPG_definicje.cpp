#include <iostream>
#include <string>
#include "RPG_klasy.h"

using namespace std;

Mag::Mag(int hp = 80, int max = 100, string moc = "brak")
{
    _punkty_zycia = hp;
    _poziom_zycia = max;
    _moc = moc;
}

void Mag::dodaj_moc(string dodatkowa_moc)
{
    _dodatkowa_moc = dodatkowa_moc;
}

void Wojownik::dodaj_sile(int s)
{
    _sila = s;
}
void Wojownik::dodaj_wytrzymalosc(int w)
{
    _wytrzymalosc = w;
}