#include <iostream>
#include <string>
#include <vector>

using namespace std;

float pi = 3.1415;

class Figura
{
    public:
        virtual float pole() = 0;
};

class Trojkat : public Figura
{
    protected:
        float _a, _h;

    public:
        Trojkat(float a = 2, float h = 1)
        {
            _a = a;
            _h = h;
        }

        float pole()
        {
            return (_a * _h) / 2;
        }
};

class Kwadrat : public Figura
{
    protected:
        float _a;

    public:
        Kwadrat(float a = 1)
        {
            _a = a;
        }

        float pole()
        {
            return _a * _a;
        }
};

class Kolo : public Figura
{
    protected:
        float _r;

    public:
        Kolo(float r = 1)
        {
            _r = r;
        }

        float pole()
        {
            return pi * _r * _r;
        }
};

class GeneratorFigur
{
    protected:
        vector<Figura*> v;

    public:
        GeneratorFigur() {}

        void dodaj_trojkat(float podstawa, float wysokosc)
        {
            Trojkat *t = new Trojkat(podstawa, wysokosc);
            v.push_back(t);
        }

        void dodaj_kwadrat(float bok)
        {
            Kwadrat *kw = new Kwadrat(bok);
            v.push_back(kw);
        }

        void dodaj_kolo(float promien)
        {
            Kolo *ko = new Kolo(promien);
            v.push_back(ko);
        }

        Figura *pobierz_figure(int i)
        {
            return v.at(i);
        }
};

int main()
{
    char choice;
    int i, x, licznik = 0;
    float a, h, r;

    GeneratorFigur fig;

    cout << "POLA FIGUR -> WIRTUALNOŚĆ" << endl;

choice:
    cout << "\nJaką figurę chcesz wprowadzić?" << endl
         << "Trójkąt: T | Kwadrat: K | Koło: O" << endl
         << "--> ";
    cin >> choice;

    cout << endl;

    switch (choice)
    {
    case 'T':
        cout << "Ile trójkątów chcesz wprowadzić?: ";
        cin >> x;
        for (i = 1; i <= x; i++)
        {
            cout << "Podaj długość podstawy " << i << " trójkąta: ";
            cin >> a;
            cout << "Podaj wysokość " << i << " trójkąta: ";
            cin >> h;
            fig.dodaj_trojkat(a, h);
            licznik++;
        }
        break;

    case 'K':
        cout << "Ile kwadratów chcesz wprowadzić?: ";
        cin >> x;
        for (i = 1; i <= x; i++)
        {
            cout << "Podaj długość boku " << i << " kwadratu: ";
            cin >> a;
            fig.dodaj_kwadrat(a);
            licznik++;
        }
        break;

    case 'O':
        cout << "Ile kół chcesz wprowadzić?: ";
        cin >> x;
        for (i = 1; i <= x; i++)
        {
            cout << "Podaj długość promienia " << i << " kołą: ";
            cin >> r;
            fig.dodaj_kolo(r);
            licznik++;
        }
        break;

    default:
        cout << "Zła wartość! Wpisz T, K lub O! " << endl
             << "Spróbuj jeszcze raz...\n"
             << endl;
        goto choice;
        break;
    };

    cout << "\nCzy chcesz dodać kolejne figuty? (T/N): ";
    cin >> choice;
    if (choice == 'T')
        goto choice;


    cout    << "\n=============================================" << endl
            << "Kolejne pola podanych przez ciebie figur:" << endl;

    for(i=1; i<=licznik; i++)
    {
        cout << i << ". " << fig.pobierz_figure(i-1)->pole() << endl;
    }
    cout << "=============================================" << endl;

        return 0;
}
