#ifndef MAP_H
#define MAP_H

#include <utility>
#include <vector>
#include <map>
#include <memory>
#include "Tile.h"

#include <string>

using namespace std;

class GameMap {
        map<pair<int, int>, vector<shared_ptr<Tile>>> game_map;
        map<int, vector<pair<int, int>>> room_floortile_coord_mapping;
        int num_rooms = 0;
    public:
        explicit GameMap();
        GameMap(string filename);

        // tileAt returns the frontmost tile pointer at (x, y)
        //     and nullptr if there is no tile there
        Tile* tileAt(int x, int y);

        // tileIDAt returns the frontmost tile's tile ID at (x, y)
        //     and the constant NOTHING if there is no tile there
        int tileIDAt(int x, int y);

        // moveTile moves the tile at (x, y) by (dx, dy)
        //     REGARDLESS of whether the tile "can" be moved or not
        // Returns false if there is no tile with the specificed pointer there
        // NOTE: does NOT check the internal x, y fields of a tile.
        bool moveTile(int x, int y, int dx, int dy, Tile* tile);

        // removeTile removes the frontmost tile at (x, y)
        //     and returns a shared_ptr to the tile
        //     and a shared_ptr initialized to nullptr if there is no tile there.
        shared_ptr<Tile> removeTile(int x, int y);

        // addTile adds a tile to the front at (x, y) and
        //     returns true if it is the first tile there.
        bool addTile(int x, int y, shared_ptr<Tile> new_tile);

        map<int, vector<pair<int, int>>>& getRoomMapping();

        // addFloorTileCoordToRoomMap adds the coord to the floor tile coord mapping
        //     at the roomNumber index (starting at 0), and returns true if successful.
        // The function fails if roomNumber >= num_rooms or if the coord already exists
        //     and returns false.
        bool addFloorTileCoordToRoomMap(int room_number, pair<int, int> coord);

        int getNumRooms();
        int setNumRooms(int);
        int addRoom();
};

#endif
