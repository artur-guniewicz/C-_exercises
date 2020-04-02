#include <iostream>
#include <cstdlib> // zawiera funkcję losującą rand()
#include <ctime>  // zawiera funkcję time()
#include <vector> // zawiera wektory
#include <string>
#include <unistd.h>

using namespace std;

class Trasa
{
    public:
        vector<int> v;

        void add(int n)
        {
            v.push_back(n);
        }
};

class Pojazd : public Trasa
{
    public:
        int liczba = 0, numer_p = 0, next_stop = 0;

        void zjazd_do_zajezdni()
        {
            if(liczba!=0)
            {
                cout << "Pojazd został opróżniony na chama :P" << endl;
                liczba = 0;
                numer_p = 0;
            }

            cout << "Pojazd zjechał do zajezdni" << endl;
            liczba = 0;
            numer_p = 0;
        }

        void jedz()
        {
            cout << "Pojazd jedzie na kolejny przystanek!\n" << endl;
            Trasa :: v[next_stop];
            next_stop++;
        }
};

class Tramwaj : public Pojazd
{
    public:
        int pojemnosc_T = 300;
        void T_na_przystanku()
        {
            switch ((rand() % 2) + 1)
            {
            case 1:
            wsiadaja:
                liczba = liczba + (rand() % (pojemnosc_T - liczba));
                break;

            case 2:
                if (liczba == 0)
                    goto wsiadaja;
                else
                    liczba = liczba - (rand() % liczba);
                break;
            };

            cout << "W tramwaju znajduje się: " << liczba << " pasażerów.\n" << endl;
        }
};

class Autobus : public Pojazd
{
    public:
        int _pojemnosc_A = 85;
        void A_na_przystanku()
        {
            switch ((rand() % 2) + 1)
            {
            case 1:
            wsiadaja:
                liczba = liczba + (rand() % (_pojemnosc_A - liczba));
                break;

            case 2:
                if(liczba == 0) goto wsiadaja;
                else liczba = liczba - (rand() % liczba);
                break;
            };

            cout << "W autobusie znajduje się: " << liczba << " pasażerów.\n" << endl;
        }
};

class Przystanek : public Trasa
{
    public:
        int nr_p;
        string nazwa_p;

        string nazwa()
        {
            return Przystanek :: nazwa_p;
        }
};

class Przystanek_Tramwajowy : public Przystanek
{
  public:
    Przystanek_Tramwajowy(string nazwa, int nr)
    {
        Przystanek :: nazwa_p = nazwa;
        Przystanek :: nr_p = nr;
    }
};

class Przystanek_Autobusowy : public Przystanek
{
    public:
        Przystanek_Autobusowy(string nazwa, int nr)
        {
            Przystanek :: nazwa_p = nazwa;
            Przystanek :: nr_p = nr;
        }
};

int main()
{
    srand(time(NULL));

    int i = 0, j = 6;

    Tramwaj tramwaj;
    Autobus autobus;
    Przystanek przystanek[10];

    przystanek[0] = Przystanek_Autobusowy("Kuklińskiego", 0);
    przystanek[1] = Przystanek_Autobusowy("Klimeckiego", 1);
    przystanek[2] = Przystanek_Autobusowy("Zabłocie", 2);
    przystanek[3] = Przystanek_Autobusowy("Rondo Grzegórzeckie", 3);
    przystanek[4] = Przystanek_Autobusowy("Hala Targowa", 4);
    przystanek[5] = Przystanek_Autobusowy("Starowiślna", 5);
    przystanek[6] = Przystanek_Tramwajowy("Poczta Główna", 6);
    przystanek[7] = Przystanek_Tramwajowy("Teatr Słowackiego", 7);
    przystanek[8] = Przystanek_Tramwajowy("Stary Kleparz", 8);
    przystanek[9] = Przystanek_Tramwajowy("Teatr Bagatela", 9);

    cout    << "SYMULACJA MPK" << endl;

    cout << "\n========================================================" << endl
         << "Autobus wyruszył na trasę!" << endl
         << "========================================================\n" << endl;

    autobus.add(0);
    autobus.add(1);
    autobus.add(2);
    autobus.add(3);
    autobus.add(4);
    autobus.add(5);


    autobus.jedz();
    cout << "Autobus jest na przystanku: " << przystanek[(i)].nazwa_p << endl;
    cout << "--> Następny przystanek to: " << przystanek[(i+1)].nazwa_p << endl;
    cout << endl;
    autobus.A_na_przystanku();
    i++;
    sleep(5);

    autobus.jedz();
    cout << "Autobus jest na przystanku: " << przystanek[(i)].nazwa_p << endl;
    cout << "--> Następny przystanek to: " << przystanek[(i + 1)].nazwa_p << endl;
    cout << endl;
    autobus.A_na_przystanku();
    i++;
    sleep(5);

    autobus.jedz();
    cout << "Autobus jest na przystanku: " << przystanek[(i)].nazwa_p << endl;
    cout << "--> Następny przystanek to: " << przystanek[(i + 1)].nazwa_p << endl;
    cout << endl;
    autobus.A_na_przystanku();
    autobus.zjazd_do_zajezdni();
    i++;
    sleep(5);

    cout    << "\n========================================================" << endl
            << "Tramwaj wyruszył na trasę!" << endl
            << "========================================================\n" << endl;

    tramwaj.add(6);
    tramwaj.add(7);
    tramwaj.add(8);
    tramwaj.add(9);

    tramwaj.jedz();
    cout << "Tramwaj jest na przystanku: " << przystanek[(j)].nazwa_p << endl;
    cout << "--> Następny przystanek to: " << przystanek[(j + 1)].nazwa_p << endl;
    cout << endl;
    tramwaj.T_na_przystanku();
    j++;
    sleep(5);

    tramwaj.jedz();
    cout << "Tramwaj jest na przystanku: " << przystanek[(j)].nazwa_p << endl;
    cout << "--> Następny przystanek to: " << przystanek[(j + 1)].nazwa_p << endl;
    cout << endl;
    tramwaj.T_na_przystanku();
    j++;
    sleep(5);

    tramwaj.jedz();
    cout << "Tramwaj jest na przystanku: " << przystanek[(j)].nazwa_p << endl;
    cout << "--> Następny przystanek to: " << przystanek[(j + 1)].nazwa_p << endl;
    cout << endl;
    tramwaj.T_na_przystanku();
    tramwaj.zjazd_do_zajezdni();
    j++;

    cout << "\n*** Koniec symulacji ***" << endl;

    return 0;
}