#include <iostream>
#include <math.h>

using namespace std;

void wypisz(char p[3][3])
{
    int i, j;

    cout << endl;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cout << "\t" << p[j][i];
        }
        cout << endl;
    }
}

int blad(int a, int b, char p[3][3]) // kontrola błędnie wprowadzonych współrzędnych
{
    int kontroler=0;

    if((a>3 || a<0) || (b>3 || b<0)) // ruch nie mieści się w polu 3x3
    {
        cout    << endl
                << "Niepoprawne współrzędne! (użyj cyfr z przedziału [1,3])" << endl
                << "Spróbuj jeszcze raz..." << endl;
        kontroler++;
    }
    else if (p[a-1][b-1] == 'X' || p[a-1][b-1] == 'O') // już wcześniej był wykonany taki ruch
    {
        cout    << endl
                << "Źle wykonany ruch! (to pole jest już zajęte)" << endl
                << "Spróbuj jeszcze raz..." << endl;
        kontroler++;
    }

    return kontroler; // jeśli 1 - błąd, jeśli 0 - brak błędu
}

void wygranaO(int x, char p[3][3])
{
    int i, j, licznik1 = 0, licznik2 = 0;

    if(x>=5)
    {
        for(i=0; i<=2; i++)
        {
            for(j=0; j<=2; j++)
            {
                if(p[i][j] == 'O') // sprawdzenie pionowe
                {
                    licznik1++;

                    if(licznik1 == 3)
                    {
                        cout << "\n***** Wygrał gracz O! *****" << endl;
                        exit(1);
                    }
                }
                else
                    licznik1 = 0;

                if(p[j][i] == 'O') // sprawdzenie poziome
                {
                    licznik2++;

                    if(licznik2 == 3)
                    {
                        cout << "\n***** Wygrał gracz O! *****" << endl;
                        exit(1);
                    }
                    else
                        licznik2 = 0;
                }
            }
        }

        // sprawdzenie ukośne
        if((p[0][0] == 'O') && (p[1][1] == 'O') && (p[2][2] == 'O'))
        {
            cout << "\n***** Wygrał gracz O! *****" << endl;
            exit(1);
        }
        else if((p[0][2] == 'O') && (p[1][1] == 'O') && (p[2][0] == 'O'))
        {
            cout << "\n***** Wygrał gracz O! *****" << endl;
            exit(1);
        }
    }
}

void wygranaX(int x, char p[3][3])
{
    int i, j, licznik1 = 0, licznik2 = 0;

    if (x >= 5)
    {
        for (i = 0; i <= 2; i++)
        {
            for (j = 0; j <= 2; j++)
            {
                if (p[i][j] == 'X') // sprawdzenie pionowe
                {
                    licznik1++;

                    if (licznik1 == 3)
                    {
                        cout << "\n***** Wygrał gracz X! *****" << endl;
                        exit(1);
                    }
                }
                else
                    licznik1 = 0;

                if (p[j][i] == 'X') // sprawdzenie poziome
                {
                    licznik2++;

                    if (licznik2 == 3)
                    {
                        cout << "\n***** Wygrał gracz X! *****" << endl;
                        exit(1);
                    }
                    else
                        licznik2 = 0;
                }
            }
        }

        // sprawdzenie ukośne
        if ((p[0][0] == 'X') && (p[1][1] == 'X') && (p[2][2] == 'X'))
        {
            cout << "\n***** Wygrał gracz X! *****" << endl;
            exit(1);
        }
        else if ((p[0][2] == 'X') && (p[1][1] == 'X') && (p[2][0] == 'X'))
        {
            cout << "\n***** Wygrał gracz X! *****" << endl;
            exit(1);
        }
    }
}

int main()
{
    int i, j, a, b, kontroler;
    char plansza[3][3];

    // stworzenie pustej planszy
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            plansza[j][i] = {'-'};
        }
    }

    cout << "GRA W KÓŁKO I KRZYŻYK!" << endl;
    wypisz(plansza);

    // max 9 ruchów graczy
    for(i=1; i<=9; i++)
    {
        if(i%2==1) // gracz nieparzysty -> gracz który zaczyna
        {
            cout << endl << "Ruch gracza O:" << endl;
        O:
            cout << "kolumna: ";
            cin >> a;
            cout << "wiersz: ";
            cin >> b;

            kontroler=blad(a, b, plansza);
            if(kontroler == 1)
                goto O;
            else
                plansza[a-1][b-1] = {'O'};

        }
        else
        {
            cout << endl <<"Ruch gracza X:" << endl;
        X:
            cout << "kolumna: ";
            cin >> a;
            cout << "wiersz: ";
            cin >> b;

            kontroler = blad(a, b, plansza);
            if(kontroler == 1)
                goto X;
            else
                plansza[a-1][b-1] = {'X'};
        }

        wypisz(plansza);

        // sprawdzenie czy nastapiła wygrana gracza O
        wygranaO(i, plansza);
        // sprawdzenie czy nastąpiła wygrana gracza X
        wygranaX(i, plansza);
    }

    return 0;
}