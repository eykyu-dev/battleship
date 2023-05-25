# Battleship Game 🚀

This repository contains a singleplayer, text-based Battleship game implemented in C++. The game allows you to play Battleship on the command line.

## Files

The repository includes the following files:

- `board.cpp`: Implements the Board class, representing the game board. It provides functions for setting up the board, placing ships, and checking for hits or misses.

- `board.h`: Declares the Board class and includes its member function and variable declarations.

- `point.h`: Defines the Point class, representing a point on the game board. It includes member functions for getting and setting the coordinates of a point.

- `pointcollection.h`: Declares the PointCollection class, representing a collection of points on the game board. It includes functions for adding and removing points from the collection.

- `ship.cpp`: Implements the Ship class, representing a ship in the game. It provides functions for placing the ship on the board and checking if the ship has been sunk.

- `ship.h`: Declares the Ship class and includes its member function and variable declarations.

- `main.cpp`: Contains the main function of the game. It includes the game loop and handles user input and gameplay logic.

## Usage

To use this project, follow these steps:

1. Clone the repository to your local machine:
git clone https://github.com/your-username/battleship.git
2. Navigate to the project directory:
cd battleship
3. Compile the source files:
g++ -o battleship main.cpp board.cpp ship.cpp
4. Run the executable:
./battleship
5. Follow the on-screen instructions to play the Battleship game.

## Contributing

If you wish to contribute to this project, you can fork the repository and create a pull request with your changes. Please ensure that your code follows the existing coding style and includes appropriate comments and documentation.

## License

This project is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute this code for personal or commercial purposes.
