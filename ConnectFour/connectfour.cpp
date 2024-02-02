//
//  connectfour.cpp
//  Connect Four Game
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Modified by Salma Emara and Ethan Hugh on 2023-09-06
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: Complete the skeletal code of the main function in this file

#include <iostream>
#include <string>
using namespace std;

#include "GameState.h"
#include "globals.h"

// Function prototypes

// The main function
int main() {
  /**********************************************************************************/
  /* Create three initialized game state objects in an array */
  /**********************************************************************************/
  const int numOfRounds = 3;
  GameState game_state[numOfRounds];

  // Read one integer from the user that represents the column
  // the player would like to place their piece (R or Y) in
  // You can assume there will be no formatting errors in the input

  int col = -1;
  int round = 0;
  int r = 0;
  int y = 0;

  while (!game_state[round].get_gameOver()) {
    if(col == -1)
    {
      cout << "Game " << (round + 1) << endl;
      cout << "Enter column to place piece: ";
      cin >> col;
    }
 
    if( cin.eof() ) {
      cerr << endl << "Game ended by user." << endl ;
      exit( 0 ) ;
    }
    if( cin.fail() ) {
      cin.clear() ;
      cin.ignore( 1000, '\n' ) ;
      col = -1 ; // giving col invalid value so it will be handled as invalid input below
    }

    while(!game_state[round].get_gameOver())
    {
    //Check validity of input and if not valid, handle accordingly
    if ((col >= 0 && col < boardSize) && game_state[round].get_gameBoard(0,col) == Empty)
    {
      cout << "column chosen: " << col << endl;
    }
    else
    {
      cout << "Invalid Column" << endl;
      break;
    }
    // The coordinates are valid; set the selectedRow and selectedColumn
    // members of the game state to the read values
    // Note that the corresponding mutators of GameState must be first
    // implemented before this works

    for(int row = 6; row >= 0; row --)
    {
      if(game_state[round].get_gameBoard(row, col) == 1 || game_state[round].get_gameBoard(row, col) == -1)
      {
        continue;
      }
      else
      {
        game_state[round].set_selectedRow(row);
        game_state[round].set_selectedColumn(col);
        int selrow = game_state[round].get_selectedRow();
        int selcol = game_state[round].get_selectedColumn();
        game_state[round].set_moveValid(true);
        if(game_state[round].get_turn() == true)
        {
          game_state[round].set_gameBoard(selrow, selcol, R);
        }
        else
        {
          game_state[round].set_gameBoard(selrow, selcol, Y);
        }
        break;
      }
    }


    
    // Call playMove
    playMove(game_state[round]);

    int i = game_state[round].get_selectedRow();
    int j = game_state[round].get_selectedColumn();

    // Print the GameState object, as prescribed in the handout
    for(int k = 0; k <= 6; k++)
    {
      for(int p = 0; p <= 6; p++)
      {
        int value = game_state[round].get_gameBoard(k, p);
        if(value == R)
        {
          cout << 'R';
        }
        else if(value == Y)
        {
          cout << 'Y';
        }
        else 
        {
          cout << "_";
        }
      }
    }

    // Check if a player won this round and if so handle accordingly
    if (game_state[round].get_gameOver() == true && game_state[round].get_gameBoard(i, j) == R)
    {
      r = r + 1;
      round++;
      cout << "R won this round!" << endl;
      col = -1;
      break;
    }
     
    else if(game_state[round].get_gameOver() == true && game_state[round].get_gameBoard(i, j) == Y)
    {
      y = y + 1;
      round++;
      cout << "Y won this round!" << endl;
      col = -1;
      break;
    }

    // Check if a player won this match and if so handle accordingly
    if(round >= 2)
    {
      if(r >= 2)
    {
      game_state[round].set_winner(R);
    }

    else if(y >= 2)
    {
      game_state[round].set_winner(Y); 
    }

    if(game_state[round].get_winner() == R)
    {
      cout << "R won the match!" << endl;
      break;
    }

    else if(game_state[round].get_winner() == Y)
    {
      cout << "Y won the match!" << endl;
      break;
    }
    }
    }

    if(game_state[round].get_winner() == R)
    {
      break;
    }
    else if(game_state[round].get_winner() == Y)
    {
      break;
    }

    game_state[round].set_gameOver(false);
    
    if (col != -1)
    {
      cout << "Enter column to place piece: ";
      cin >> col;
    }
    game_state[round].set_gameOver(false);
  }
}
  