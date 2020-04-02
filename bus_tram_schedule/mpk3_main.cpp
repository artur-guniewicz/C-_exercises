#include <iostream>
#include "mpk-klasy.h"
#include <string>
using namespace std;

int main(){
  Bus bus32 = Bus(32);
  Bus bus53 = Bus(53);
  Tram tram28 = Tram(28);
  Tram tram86 = Tram(86);
  Route r1, r2;
  tramStop t6(6), t10(10), t14(14), t18(18), t26(26), t30(30), t35(35);
  busStop b2(2), b8(8), b13(13), b20(20), b27(27), b31(31), b33(33);
  r1.stops = {t6, b8, t14, t18, b27, t30, b33};
  r2.stops = {b2, t10, b13, b20, t18, t26, b31, b33};
  bus32.setRoute(r1);
  bus53.setRoute(r2);
  tram28.setRoute(r1);
  tram86.setRoute(r2);
  bus32.fullRoute();
  tram28.fullRoute();
  bus53.fullRoute();
  tram86.fullRoute();

  return 0;
}
