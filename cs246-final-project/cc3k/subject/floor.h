#include <utility>
using namespace std;
class Floor {
        int x, y; // x, y coordinates
    public:
        Floor(int x, int y);
        int getTileID(int, int);
        Floor getTilePtr(int, int);
        virtual ~Floor() = 0;
};
