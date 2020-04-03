#include <iostream>
#include <string>

using namespace std;

class Postac
{
    protected:
        string _nazwa, _l_reka, _p_reka, _nogi, _tors, _glowa;

    public:
        Postac() {}
        int _poziom_zycia, _punkty_zycia;
        virtual void dodaj_l_reka(string) = 0;
        virtual void dodaj_p_reka(string) = 0;
        virtual void dodaj_nogi(string) = 0;
        virtual void dodaj_tors(string) = 0;
        virtual void dodaj_glowa(string) = 0;
        virtual void ustal_nazwe(string) = 0;
        virtual void statystyki() = 0;
        virtual void przedmioty() = 0;
};

class Mag : public Postac
{
    protected:
        string _dodatkowa_moc;

    public:
        string _moc;
        Mag(int, int, string);
        void dodaj_moc(string);
};

class Wojownik : public Postac
{
    public:
        int _sila, _wytrzymalosc;
        Wojownik(int, int, int, int);
        void dodaj_sile(int);
        void dodaj_wytrzymalosc(int);
};

class Przedmiot
{
    public:
        Przedmiot() {}
        string _nazwa_przedmiotu;
        virtual void wypisz_statystyki() = 0;
};

class Tarcza : public Przedmiot
{
    protected:
        int _bonus;
    public:
        Tarcza(string, int);
};

class Miecz_Magiczny : public Przedmiot
{
public:
};

class Miecz_Zwykly : public Przedmiot
{
public:
};

class Miecz : public Miecz_Magiczny, public Miecz_Zwykly
{
};

class Laska
{
};