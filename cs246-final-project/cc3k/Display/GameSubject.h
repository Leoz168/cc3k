#ifndef GAMESUBJECT_H
#define GAMESUBJECT_H

#include <vector>
#include "observer.h"
using namespace std;

class GameSubject {
        vector<Observer*> observers;
    public:
        void attach(Observer *o);
        void detach(Observer *o);
        void notifyobserver();
        virtual ~GameSubject() = 0;
};

#endif
