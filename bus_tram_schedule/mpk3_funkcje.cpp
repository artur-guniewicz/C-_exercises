#include <iostream>
#include <vector>
#include "mpk-klasy.h"
using namespace std;

busStop::busStop(int id){
  id_no = id;
  forBus = true;
  forTram = false;
}

tramStop::tramStop(int id){
  id_no = id;
  forBus = true;
  forTram = true;
}

Vehicle::Vehicle(int ln /*= 0*/, int cap /*= 1*/){
  capacity = cap;
  line = ln;
}

void Vehicle::setRoute(Route a){
  route = a;
}

void Vehicle::begin(){

  if(checkStop()){
    displayStop();
    getOn();
    go();
    cout << endl;
  }
  
}

bool Vehicle::go(){
  if (stop_no < route.stops.size()){
    stop_no += 1;
    return true;
  }
  else{
    return false;
  }
}

bool Vehicle::checkStop(){
  if (route.stops[stop_no].forTram == true && type == "TRAM"){
    return true;
  }
  else if (route.stops[stop_no].forBus == true && type == "BUS"){
    return true;
  }
  else return false;
}

void Vehicle::stop(){
  if (checkStop() && passengers != 0){
    displayStop();
    getOn();
    getOff();
  }
  else begin();
}

void Vehicle::displayStop(){
  cout << "Stop ID: " << route.stops[stop_no].id_no << endl;
}

void Vehicle::goBack(){
  passengers = 0;
  cout << "All passengers get off. Returning to base." << endl;
}

void Vehicle::getOn(){
  int starting = rand() % 50 + 2;
  passengers += starting;
  cout << starting << " people get on." << endl;
}

void Vehicle::getOff(){
  int ending = rand() % passengers + 2;
  passengers -= ending;
  cout << ending << " people get off." << endl << endl;
}

void Vehicle::fullRoute(){
  cout << "\n========= " << type << " LINE " << line << " =========\n";

  stop_no = 0;
  passengers = 0;
  begin();
  while(true){
    stop();
    if(go()){
      continue;
    }
    else{
      goBack();
      break;
    }
  }
}

Bus::Bus(int ln /*= 0*/, int cap /*= 200*/){
  line = ln;
  capacity = cap;
  type = "BUS";
}

Tram::Tram(int ln, int cap /*= 300*/){
  line = ln;
  capacity = cap;
  type = "TRAM";
}
