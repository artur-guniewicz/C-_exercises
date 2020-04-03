#include <iostream>

using namespace std;

class SterownikKotla;
class Termostat;

class Kociol
{
    friend void wygaszenie(Kociol &);
    friend void usuniecie_paliwa(Kociol &);

public:
    Kociol() {}

private:
    int ilosc_paliwa;
    double temperatura;
};

class Kaloryfer
{
    friend void zmien_temp();

public:
    Kaloryfer() {}

private:
    double temperatura;
    void zmien_temp(int new_temp)
    {
        temperatura = new_temp;
    }
};

class Kontroler
{
public:
    Kontroler() {}
    virtual void zmien_temp() = 0;
};

class Termostat : public Kontroler
{
    friend class Kaloryfer;

public:
    Termostat() {}

    void zmien_temp(Kaloryfer &k, const int temp)
    {
        k.temperatura = temp;
    }
};

class SterownikKotla : public Kontroler
{
    friend class Kociol;

public:
    SterownikKotla() {}

    void zmien_temp(Kociol &k, const int temp)
    {
        k.temperatura = temp;
    }

    void zmien_il_pal(Kociol &k, const int il_pal)
    {
        k.ilosc_paliwa = il_pal;
    }
};

void wygaszenie(Kociol &k)
{
    k.temperatura = 0;
}

void usuniecie_paliwa(Kociol &k)
{
    k.ilosc_paliwa = 0;
}

int main()
{
}