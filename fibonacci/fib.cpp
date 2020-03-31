#include <iostream>

using namespace std;

long int fib(int n)
{
    long int wynik;
    if(n == 0) wynik = 0;
    else if(n == 1) wynik = 1;
    else wynik = fib(n-2) + fib(n-1);

    return wynik;
}

void c(int n)
{
    int i;

    for(i=0; i<n ;i++)
    {
        cout << "F(" << i << ") = " << fib(i) << endl;
    }
}

void k(int n)
{
    int choice;

choice:
    cout << "Który element podać?: ";
    cin >> choice;

    if(choice > n || choice < 0)
    {
        cout    << "Zła wartość! Podaj liczbę ze zbioru [0, " << n << "]" << endl
                << "Spróbuj jeszcze raz... \n" << endl;
        goto choice;
    }

    else
    {
        cout << "--> F(" << choice << ") = " << fib(choice) << endl;
    }
}

int main()
{
    int d;
    char choice;

    cout << "CIĄG FIBONACCIEGO \"n\" LICZB:\n" << endl;
D:
    cout << "Podaj długość ciągu (n): ";
    cin >> d;
    if(d < 0)
    {
        cout    << "Zła wartość! Podaj liczbę naturalną [0, inf)" << endl
                << "Spróbuj jeszcze raz... \n" << endl;
        goto D;
    }
    cout << endl;

choice:
    cout << "Wypisać cały ciąg (C) czy konkretny element (K)? (C/K): ";
    cin >> choice;

    cout << endl;

    switch (choice)
    {
        case 'C':
            c(d);
            break;

        case 'K':
            k(d);
            break;

        default:
            cout    << "Zła wartość! Podaj literę C lub K!" << endl
                    << "Spróbuj jeszcze raz... \n" << endl;
            goto choice;
            break;
    };

    return 0;
}