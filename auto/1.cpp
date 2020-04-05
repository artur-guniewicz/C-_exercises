#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Auto
{
    protected:
        double _moc = 100.0;

    public:
        virtual double max_speed() const
        {
            return _moc;
        }

        virtual ~Auto() {}
};

class Temp_Auto : public Auto
{
    private:
        double _moc_temp = 50.0;
    public:
        double max_speed() const
        {
            return min(_moc, _moc_temp);
        }
};

double min_time(const Auto &brum, double distance)
{
    return distance / brum.max_speed();
}

int main()
{
    Auto brum;
    Temp_Auto brum2;

    cout << min_time(brum, 100.0) << endl;
    cout << min_time(brum2, 100.0) << endl;


    return 0;
}