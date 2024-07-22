#include <vector>
#include "observer/observer.h"
using namespace std;

class GameSubject {
        vector<Observer*> observers;
    public:
        void attach(Observer *o);
        void detach(Observer *o);
        void notifyobserver();
        virtual ~GameSubject() = 0;
};