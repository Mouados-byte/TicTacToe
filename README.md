# Tic Tac Toe Game
This project is a simple implementation of the classic Tic Tac Toe game in C++. The game is played on a 3x3 grid and can be played by two players or against a computer player.

## Getting Started
Clone the repository and run the following command to compile the code:

Copy code
```
g++ Tictactoe.cpp -o tictactoe -std=c++11
```
This will create an executable file "tictactoe" that you can run on your platform.

The program should be able to run on any platform that supports C++11.

## Game rules
- The game is played on a 3x3 grid.
- The players take turns to place their mark (X or O) on the grid.
- The player who successfully places three of their marks in a horizontal, vertical or diagonal row wins the game.
- If the grid is filled and no player has won, the game is a draw.
## Features
- The program allows the players to enter their desired mark (X or O).
- The program checks for a win or draw after each move.
- The program prints the game board after each move.
- The program allows the players to play multiple rounds.
- The program also includes an option to play against a computer player, which uses the minimax algorithm to make its moves.
## Limitations
The program does not include any error handling for invalid inputs.
## Authors
This project was developed by me, and I am the only author.
