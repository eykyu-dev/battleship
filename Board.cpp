//
//  Board.cpp
//  Battleship
//

#include "Board.h"
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

Board::Board(){
  //sets up board
  srand(time(NULL));
  for(int i = 0; i < 10; i++){
    for(int c = 0; c < 10; c++){
      shipboard[i][c] = '~';
    }
  }
  //make sure that the array is reset...
  for(int i = 0; i < 4; i++){
    ships[i] = NULL;
  }
  for(int i = 0; i < 4; i++){
    ships[i] = generateShipWithLength(5-i);
  }
}

Board::~Board(){
  //Goes through the array of ships and deletes them and returns the memory
  for(int i = 0; i<4; i++){
    delete [] ships[i];
    ships[i] = NULL;
  }
}

bool Board::fireShot(int x, int y){
  //create new pointer object
  point shotFired(x, y);
  //cycles through the array of ships to test all of them.
  for(int i = 0; i<4; i++){
    //adds to hits
    ships[i]->shotFiredAtPoint(shotFired);
    //test to see if the ship contains the point.
    if(ships[i]->containsPoint(shotFired) == true){
      shipboard[x][9-y] = 'X';
      return true;
    }
  }
  shipboard[x][9-y] = 'O';
  return false;
}

Ship* Board::generateShipWithLength(int l){

  direction tempShip;
  point tempOrigin;
  int directionint;
  int length = l;
  directionint = rand() % 2;

  if(directionint == 0){
    tempShip = VERTICAL;
    int tempx = (rand()%(10));
    int tempy = (rand()%(10-length));
    tempOrigin.setX(tempx);
    tempOrigin.setY(tempy);
  }

  else if(directionint == 1){
    tempShip = HORIZONTAL;
    int tempx = (rand()%(10-length));
    int tempy = (rand()%(10));
    tempOrigin.setY(tempy);
    tempOrigin.setX(tempx);
  }
  Ship *ptr = NULL;
  ptr = new Ship(tempOrigin, tempShip, length);

  for(int i = 0; i < 4; i++){
    // cout << "work" << endl;
    if(ships[i] != NULL){
      while(ptr->collidesWith(*ships[i])){
        // cout << "I'm stuck in collidesWith";
        if(directionint == 0){
          int tempx = (rand()%(10));
          int tempy = (rand()%(10-length));
          tempOrigin.setX(tempx);
          tempOrigin.setY(tempy);
        }

        else if(directionint == 1){
          int tempx = (rand()%(10-length));
          int tempy = (rand()%(10));
          tempOrigin.setY(tempy);
          tempOrigin.setX(tempx);
        }
        delete [] ptr;
        ptr = new Ship(tempOrigin, tempShip, length);
      }
    }
  }
  // cout << directionint << endl;
  // cout << "X: " << tempOrigin.getX() << ' ' << "Y: " << tempOrigin.getY() << endl;
  ptr = new Ship(tempOrigin, tempShip, length);
  return ptr;
}

void Board::display(){
  for(int i = 0; i < 10; i++){
    cout << 9-i << ' ';
    for(int c = 0; c < 10; c++){
      cout << shipboard[c][i] << ' '; 
    }
    cout << endl;
  }
  cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
}

int Board::unsunkShipCount(){
  //tally to hold the ship count
  int shipsLeft = 0;
  //testing all ships in pointer array
  for(int i = 0; i < 4; i++){
    if(ships[i]->isSunk() == false){
      shipsLeft++;
    }
  }
  return shipsLeft;
}
