#include <GameSubject.h>
#include <iostream>
#include "ANSIconsts.h"

using namespace std;

void GameSubject::attach(Observer *o) {
    observers.emplace_back(o);
}
void GameSubject::detach(Observer *o) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
    if (*it == o) {
      observers.erase(it);
      break;
    }
  }
}
void GameSubject::notifyobserver() {
    cout << CLEAR_COMMAND << endl;
    for(auto it: observers) {it->notify();}
}
