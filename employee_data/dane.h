#include <iostream>
#include <string>

using namespace std;

class Pracownik
{
  public:
    void setImie(string imie);
    void setNazwisko(string nazwisko);
    void setUlica(string ulica);
    void setDom(string dom);
    void setKod(string kod);
    void setMiejscowosc(string miejscowosc);

    string getImie();
    string getNazwisko();
    string getUlica();
    string getDom();
    string getKod();
    string getMiejscowosc();

  private:
    string _imie;
    string _nazwisko;
    string _ulica;
    string _dom;
    string _kod;
    string _miejscowosc;
};