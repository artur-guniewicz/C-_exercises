/* zmienne i sizeof */

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int to_jest_zmienna;
    unsigned int tylko_dodatnie;
    float zmiennoprzecinkowa;
    char znak;
    unsigned char tez_znak;
    int abc=-53;

    tylko_dodatnie=22;
    zmiennoprzecinkowa=12.42;
    tez_znak='c';

    cout << "Wypisujemy zmienne:" << endl;
    cout << "to_jest_zmienna = " << to_jest_zmienna << endl;
    cout << "tylko_dodatnie = " << tylko_dodatnie << endl;
    cout << "zmiennoprzecinkowa = " <<  zmiennoprzecinkowa << endl;
    cout << "znak = " << znak << endl;
    cout << "tez_znak = " << tez_znak << endl;
    cout << "abc = " << abc << endl;

    printf("\n\n");

    cout << "sizeof(bool) = " << sizeof(bool) << endl;
    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(unsigned char) = " << sizeof(unsigned char) << endl;
    cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << endl;
    cout << "sizeof(short) = " << sizeof(short) << endl;
    cout << "sizeof(unsigned short) = " << sizeof(unsigned short) << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(unsigned int) = " << sizeof(unsigned int) << endl;
    cout << "sizeof(long) = " << sizeof(long) << endl;
    cout << "sizeof(unsigned long) = " << sizeof(unsigned long) << endl;
    cout << "sizeof(long long) = " << sizeof(long long) << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(long double) = " << sizeof(long double) << endl;

    return 0;
}