#include <iostream>
#include <vector>
#include <algorithm> // zawiera funkcję sort()

using namespace std;

void wypisz(vector<int> v, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int i, j, n, element;
    char choice;

    vector<int> v;

    cout << "OPERACJE NA WEKTORACH:" << endl;

N:
    cout << "\nIle elementów chcesz dodać do wektora?: ";
    cin >> n;

    if (n == 0)
    {
        cout << "Nie wprowadzisz żadnego elementu! Chcesz jednak jakiś dodać? (T/N): ";
    choice:
        cin >> choice;
        if (choice == 'T') goto N;
        else if (choice == 'N')
        {
            cout << "\nWektor jest pusty!" << endl;
            goto cont;
        }
        else
        {
            cout << "Zła wartość! Wpisz T lub N: ";
            goto choice;
        }
    }
    else if (n < 0)
    {
        cout << "Zła wartość! Podaj liczbę naturalną z przedziału [0, inf)" << endl
             << "Spróbuj jeszcze raz..." << endl;
        goto N;
    }

    cout << "\nPodaj " << n << " RÓŻNYCH elementów (oddzielając je klawiszem ENTER): " << endl;
    for(i=0; i<n; i++)
    {
        cin >> element;
        v.push_back(element);
        for (j = i-1; j >= 0; j--)
        {
            if (v[j] == v[i])
            {
                cout << "Podany element już istnieje!" << endl
                     << "Spróbuj jeszcze raz... (ilość elementów pozostałych do wpisania: " << n-i << " )" << endl;
                v.pop_back();
                i--;
            }
        }
    }

    cout << "\nStworzony przez ciebie wektor:" << endl;
    wypisz(v, n);

    sort(v.begin(), v.end());

    cout << "\nWektor posortowany:" << endl;
    wypisz(v, n);

cont:

    return 0;
}