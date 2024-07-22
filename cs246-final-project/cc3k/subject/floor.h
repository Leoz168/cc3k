#include <utility>
using namespace std;
class Floor {
        int x, y; // x, y coordinates
    public:
        Floor(int x, int y);
        virtual int getTileID(int x, int y);
        Floor getTilePtr(int x, int y);
        virtual ~Floor() = 0;
};
