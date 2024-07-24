#include "GameSubject.h"

void GameSubject::attach(Observer *o) {
    observers.emplace_back(o);
}

void GameSubject::detach(Observer *o) {
    for (auto it = observers.begin(); it != observers.end();) {
        if (*it == o) it = observers.erase(it);
        else ++it;
    }
}
void GameSubject::notifyobserver() { for (auto o: observers) o->notify(); }

GameSubject::~GameSubject() {}
