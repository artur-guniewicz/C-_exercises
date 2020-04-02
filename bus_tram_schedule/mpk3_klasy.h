#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Stop{
public:
  int id_no;
  bool forBus;
  bool forTram;
};


class busStop : public Stop{
public:
  busStop(int id);
};

class tramStop : public Stop{
public:
  tramStop(int id);
};

class Route{
public:
  vector<Stop> stops;
};

class Vehicle{
protected:
  int capacity;
  int passengers;
  int stop_no;
  int line;
  string type;
  Route route;
public:
  Vehicle(int ln = 0, int cap = 1);
  void setRoute(Route a);
  void begin();
  bool go();
  bool checkStop();
  void stop();
  void displayStop();
  void goBack();
  void getOn();
  void getOff();
  void fullRoute();
};

class Bus : public Vehicle{
public:
  Bus(int ln = 0, int cap = 200);
};

class Tram : public Vehicle{
public:
  Tram(int ln, int cap = 300);
};
