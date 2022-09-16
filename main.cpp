//Ethan Yu - CS110B Battleship Assignment 12. Battleship Board Implementation
// This is by far, the hardest assignment I've ever had to do.

#include "PointCollection.h"
#include "Ship.h"
#include "Board.h"
#include <iostream>

using namespace std;


int main(){
  int x, y;
  Board battleship;
  while(battleship.unsunkShipCount() != 0){
    battleship.display();
    cout << "\nEnter Coords: ";
    cin >> x >> y;
    if(battleship.fireShot(x, y) == true){
      cout << "\nHit!";
    }
    else{
      cout << "\nMiss!";
    }
    for(int i = 0; i < 2; i++){
      cout << '\n';
    }
  }
}

// Testing Full Board
// int main(){
//   int x, y;
//   Board battleship;
//   for(int i = 0; i < 10; i++){
//     for(int j = 0; j< 10; j++){

//       battleship.fireShot(i,j);
//     }
//   }
//   battleship.display();
// }


// SAMPLE OUTPUT
// 9 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 8 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 7 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 6 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 5 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 4 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 3 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 2 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 1 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 0 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
//   0 1 2 3 4 5 6 7 8 9

// Enter Coords: 2 3

// Miss!

// 9 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 8 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 7 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 6 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 5 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 4 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 3 ~ ~ O ~ ~ ~ ~ ~ ~ ~
// 2 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 1 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 0 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
//   0 1 2 3 4 5 6 7 8 9

// Enter Coords: 2 5

// Miss!

// 9 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 8 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 7 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 6 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 5 ~ ~ O ~ ~ ~ ~ ~ ~ ~
// 4 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 3 ~ ~ O ~ ~ ~ ~ ~ ~ ~
// 2 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 1 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
// 0 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
//   0 1 2 3 4 5 6 7 8 9

// Enter Coords: 3 7

// Hit!