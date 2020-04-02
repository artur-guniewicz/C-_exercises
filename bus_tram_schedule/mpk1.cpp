#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
// #include <windows.h>
#include <unistd.h>

using namespace std;
class Trasa
{
public:
        vector<int> wektor;
        void Add_busstop(int nr)
        {
          wektor.push_back(nr);
        };

};

class Pojazd : public Trasa
{
public:
    int l_p=0;//liczba pasażerow
    int nr_przystanku=0;
    int kol_przystanek=0;
    void zjazd_do_zajezdni()
    {
        if(l_p!=0){
            cout<<"Autobus/Tramwaj zostal oprozniony na chama :)"<<endl;
            l_p=0;
            nr_przystanku=0;
            }else cout<<"Autobus zjechal do zajezdni"<<endl;
              l_p=0;
              nr_przystanku=0;
    }
   /* void jedz()
    {
        cout<<"Przyjecha³em z: "<<wektor[i]<<endl;
        cout<<"Obecnie jestem na: "<<wektor[i+1]<<endl;
    } */
    int zajezdza_na_przystanek();
    void Jedz()
    {
        cout<<"Jade na kolejny przystanek!"<<endl;
        Trasa::wektor[kol_przystanek];
        kol_przystanek++;

    }
};

class Przystanek : public Trasa
{
public:
    int numerprzystanku;
    string nazwa_przystanku;
    string Nazwaprzystanku()
    {
        return Przystanek :: nazwa_przystanku;
    }

};
class Autobusowy : public Przystanek
{
    public:
    Autobusowy(string nazwa, int numer)
    {
        Przystanek::nazwa_przystanku=nazwa;
        Przystanek::numerprzystanku=numer;
    };
};
class Tramwajowy : public Przystanek
{
public:
    Tramwajowy(string nazwa, int numer)
    {
        Przystanek::nazwa_przystanku=nazwa;
        Przystanek::numerprzystanku=numer;
    }
};
class Autobus : public Pojazd
{
public:
    int max_pojemnosc_a=150;
    void zajezdza_na_przystanek()
    {
        int wsiadaja, wysiadaja;//randomowa liczba pasazerow wsiada i wysiada
        srand(time(NULL));
        wsiadaja=rand()%max_pojemnosc_a;
        wysiadaja=rand()%max_pojemnosc_a;

        if((l_p+wsiadaja)<max_pojemnosc_a) l_p+=wsiadaja;
        if((l_p-wysiadaja)>0) l_p-=wysiadaja;
        cout<<endl<<"W autobusie aktualnie znjaduje sie: "<<l_p<<" osob"<<endl;

    }

    /*void max_pojemnosc_a()
    {
        int mp_a=120;
    }*/
};
class Tramwaj : public Pojazd
{
public:
    int max_pojemnosc_t=450;
    void dojezdza_na_przystanek()
    {
        int wsiadaja, wysiadaja;//randomowa liczba pasazerow wsiada i wysiada
        srand(time(NULL));
        wsiadaja=rand()%max_pojemnosc_t;
        wysiadaja=rand()%max_pojemnosc_t;

        if((l_p+wsiadaja)<max_pojemnosc_t) l_p+=wsiadaja;
        if((l_p-wysiadaja)>0) l_p-=wysiadaja;
        cout<<endl<<"W tramwaju aktualnie znjaduje sie: "<<l_p<<" osob"<<endl;

    }

};


int main()
{
    int i=0;
    cout << "Witaj w programie do symulacji przejazdu autobusu/tramwaju w Krakowskim MPK :)" << endl;
    cout << "Tak wyglada rozklad jazdy na dziś " << endl;
    cout << "Zaczynamy jazde!" << endl;

    Przystanek krakowski_przystanek[8];
    krakowski_przystanek[0]=Autobusowy("Miesteczko AGH", 0);
    krakowski_przystanek[1]=Autobusowy("Kawiory", 1);
    krakowski_przystanek[2]=Autobusowy("Jubliat", 2);
    krakowski_przystanek[3]=Autobusowy("Muzeum Narodowe", 3);
    krakowski_przystanek[4]=Autobusowy("Konopnickiej", 4);
    krakowski_przystanek[5]=Tramwajowy("Centrum Kongresowe Ice", 5);
    krakowski_przystanek[6]=Tramwajowy("Szwedzka", 6);
    krakowski_przystanek[7]=Tramwajowy("Kapelanka", 7);


    Autobus MAN;
    Tramwaj krakowiak;;
    MAN.Add_busstop(1);
    MAN.Add_busstop(2);
    MAN.Add_busstop(5);
    MAN.Add_busstop(7);
    MAN.Add_busstop(8);
    MAN.Add_busstop(9);

    MAN.zjazd_do_zajezdni();
    MAN.Jedz();

	cout<<endl<<"Jestem wlasnie na przystanku: "<<krakowski_przystanek[(i)].nazwa_przystanku << endl;
	cout<<endl<<"Nastepny przystanek to: " << krakowski_przystanek[(i + 1)].nazwa_przystanku << endl;
	MAN.zajezdza_na_przystanek();
	i++;
	sleep(5);


    MAN.Jedz();
	cout<<endl<<"Jestem teraz na przystanku: "<<krakowski_przystanek[(i)].nazwa_przystanku << endl;
	cout<<endl<<"Nastepny przystanek to: " << krakowski_przystanek[(i + 1)].nazwa_przystanku << endl;
	MAN.zajezdza_na_przystanek();
	i++;
	sleep(5);

     MAN.Jedz();
	cout<<endl<<"Jestem na przystanku: "<<krakowski_przystanek[(i)].nazwa_przystanku << endl;
	cout<<endl<<"Nastepny przystanek to: " <<krakowski_przystanek[(i + 1)].nazwa_przystanku << endl;
	MAN.zajezdza_na_przystanek();
	MAN.zjazd_do_zajezdni();
	i++;
	sleep(5);


	krakowiak.Add_busstop(0);
    krakowiak.Add_busstop(2);
    krakowiak.Add_busstop(3);
    krakowiak.Add_busstop(6);
    krakowiak.Add_busstop(7);
    krakowiak.Add_busstop(2);

    cout<<endl<<endl<<"Zaczynamy jazde tramwajem!"<<endl;

    krakowiak.zjazd_do_zajezdni();
    krakowiak.Jedz();
	cout<<endl<<"Jestem wlasnie na przystanku: "<<krakowski_przystanek[i].nazwa_przystanku << endl;
	cout<<endl<<"Nastepny przystanek to: " << krakowski_przystanek[(i + 1)].nazwa_przystanku << endl;
	krakowiak.dojezdza_na_przystanek();
	i++;
	sleep(5);

    krakowiak.Jedz();
	cout<<endl<<"Obecnie znajduje sie na przystanku: "<<krakowski_przystanek[i].nazwa_przystanku << endl;
	cout<<endl<<"Nastepny przystanek to: " << krakowski_przystanek[(i + 1)].nazwa_przystanku << endl;
	krakowiak.dojezdza_na_przystanek();
	i++;
	sleep(5);

    krakowiak.Jedz();
	cout<<endl<<"Jestem wlasnie na przystanku: "<<krakowski_przystanek[(i)].nazwa_przystanku << endl;
	cout<<endl<<"Nastepny przystanek to: " <<krakowski_przystanek[(i + 1)].nazwa_przystanku << endl;
	krakowiak.dojezdza_na_przystanek();
	krakowiak.zjazd_do_zajezdni();
	i++;

	cout<<"KONIEC"<<endl;




    return 0;

}
