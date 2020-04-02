#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
// #include <windows.h>
#include <unistd.h>

using namespace std;

class trasa
{
public:

    vector<int> przystanki;

    void dodaj_przystanek(int numer)
    {
        przystanki.push_back(numer);
    }
};

class przystanek
{
public:

    int numer_przystanku;
    string nazwa_przystanku;

    string nazwa_przystanku_funkcja()
    {
        return przystanek::nazwa_przystanku;
    }
};

class autobusowy : public przystanek
{
public:

    autobusowy(string nazwa, int numer)  //konstruktor
    {
        przystanek::nazwa_przystanku = nazwa;
        przystanek::numer_przystanku = numer;
    };
};

class tramwajowy : public przystanek
{
public:

    tramwajowy(string nazwa, int numer)  //konstruktor
    {
        przystanek::nazwa_przystanku = nazwa;
        przystanek::numer_przystanku = numer;
    };
};

class pojazd : public trasa
{
public:

    int ilosc_pasazerow = 0;
    int ktory_przystanek = 0;

    void zjazd_do_zajezdni()
    {
        if(ilosc_pasazerow != 0)
        {
            cout << "Dojechalismy do zajezdni, wszyscy pasazerowie musza wysiasc\n";
            cout << "Pojazd zakonczyl trase\n";

            ilosc_pasazerow = 0;
            ktory_przystanek = 0;
        }
    }

    // przyjazd_na_przystanek();

    void jedz()
    {
        cout << "Jedziemy na kalejny przystanek\n";

        trasa::przystanki[ktory_przystanek];
        ktory_przystanek++;
    }
};

class autobus : public pojazd
{
public:

    int ilosc_miejsc_autobus = 90;

    void przyjazd_na_przystanek()
    {
        int dodaj, odejmij;

        srand(time(NULL));
        dodaj = rand()%ilosc_miejsc_autobus;
        odejmij = rand()%ilosc_miejsc_autobus;

        if((ilosc_pasazerow+dodaj)<ilosc_miejsc_autobus) ilosc_pasazerow+=dodaj;
        if((ilosc_pasazerow-odejmij)>0) ilosc_pasazerow-=odejmij;

        cout << "W autobusie znajduje sie "<< ilosc_pasazerow << " pasazerow\n" << endl;
    }

};

class tramwaj : public pojazd
{
public:

    int ilosc_miejsc_tramwaj = 150;

    void przyjazd_na_przystanek()
    {
        int dodaj, odejmij;

        srand(time(NULL));
        dodaj = rand()%ilosc_miejsc_tramwaj;
        odejmij = rand()%ilosc_miejsc_tramwaj;

        if((ilosc_pasazerow+dodaj)<ilosc_miejsc_tramwaj) ilosc_pasazerow+=dodaj;
        if((ilosc_pasazerow-odejmij)>0) ilosc_pasazerow-=odejmij;

        cout << "W tramwaju znajduje sie "<< ilosc_pasazerow << " pasazerow\n" << endl;
    }
};

int main()
{
    cout << "Symulacja MPK\n";

    przystanek przystanek_tablica[10];
    przystanek_tablica[0] = autobusowy("Nazwa przystanku numer 1", 0);
    przystanek_tablica[1] = autobusowy("Nazwa przystanku numer 2", 1);
    przystanek_tablica[2] = autobusowy("Nazwa przystanku numer 3", 2);
    przystanek_tablica[3] = autobusowy("Nazwa przystanku numer 4", 3);
    przystanek_tablica[4] = autobusowy("Nazwa przystanku numer 5", 4);
    przystanek_tablica[5] = tramwajowy("Nazwa przystanku numer 6", 5);
    przystanek_tablica[6] = tramwajowy("Nazwa przystanku numer 7", 6);
    przystanek_tablica[7] = tramwajowy("Nazwa przystanku numer 8", 7);
    przystanek_tablica[8] = tramwajowy("Nazwa przystanku numer 9", 8);
    przystanek_tablica[9] = tramwajowy("Nazwa przystanku numer 10", 9);

    autobus autobus_numer_1;
    tramwaj tramwaj_numer_1;

    autobus_numer_1.dodaj_przystanek(1);
    autobus_numer_1.dodaj_przystanek(2);
    autobus_numer_1.dodaj_przystanek(5);
    autobus_numer_1.dodaj_przystanek(7);
    autobus_numer_1.dodaj_przystanek(8);
    autobus_numer_1.dodaj_przystanek(9);

	tramwaj_numer_1.dodaj_przystanek(0);
    tramwaj_numer_1.dodaj_przystanek(2);
    tramwaj_numer_1.dodaj_przystanek(3);
    tramwaj_numer_1.dodaj_przystanek(6);
    tramwaj_numer_1.dodaj_przystanek(8);
    tramwaj_numer_1.dodaj_przystanek(2);

    //symulacja autobusu numer 1
    cout << "symulacja autobusu numer 1" << endl;

    for(int i=0; i<6; i++)
    {
        autobus_numer_1.jedz();
        cout << "Jestem na przystanku: " << przystanek_tablica[i].nazwa_przystanku_funkcja() << endl;
        cout << "Nastepny przystanek to: " << przystanek_tablica[i + 1].nazwa_przystanku_funkcja() << endl;
        autobus_numer_1.przyjazd_na_przystanek();
        sleep(5);
    }
    autobus_numer_1.zjazd_do_zajezdni();

    //symulacja tramwaju numer 1
    cout << "sumulacja tramwaju numer 1" << endl;

    for(int i=0; i<6; i++)
    {
        tramwaj_numer_1.jedz();
        cout << "Jestem na przystanku: " << przystanek_tablica[i].nazwa_przystanku_funkcja() << endl;
        cout << "Nastepny przystanek to: " << przystanek_tablica[i + 1].nazwa_przystanku_funkcja() << endl;
        tramwaj_numer_1.przyjazd_na_przystanek();
        sleep(5);
   }
	tramwaj_numer_1.zjazd_do_zajezdni();

	cout << "Koniec symulacji MPK\n";

    return 0;
}
