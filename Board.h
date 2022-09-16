//
//  Board.h
//  Battleship
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Ship.h"
#include "PointCollection.h"

class Board{
  private:
    PointCollection misses;
    char shipboard[10][10];
    Ship* generateShipWithLength(int l);
  public:
    Ship *ships[4];
    Board();
    ~Board();
    bool fireShot(int x, int y);
    int unsunkShipCount();
    void display();
    
};

#endif
