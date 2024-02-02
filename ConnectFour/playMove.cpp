//
//  playMove.cpp
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
//  ECE244 Student: write your code for playMove in this file

#include "GameState.h"
#include "globals.h"

// Function prototypes (if you need)



void playMove(GameState& game_state) {

  // Change gameOver
  int i = game_state.get_selectedRow();
  int j = game_state.get_selectedColumn();

  if((j + 3) <= 6)
  {
    for(int k = j; k <= 6 ; k++)
    {
      if ((game_state.get_gameBoard(i, k)) == (game_state.get_gameBoard(i, (k + 1))) == (game_state.get_gameBoard(i, (k + 2))) == (game_state.get_gameBoard(i, (k + 3))))
      {
        game_state.set_gameOver(true);
        break;
      }
      else
      {
        game_state.set_gameOver(false);
        break;
      }
    }
  }//Horizontal check in the forward direction 

  if((j - 3) >= 0)
  {
    for (int k = j; k >= 0; k--)
    {
      if ((game_state.get_gameBoard(i, k)) == (game_state.get_gameBoard(i,(k - 1))) == (game_state.get_gameBoard(i,(k - 2))) == (game_state.get_gameBoard(i,(k - 3))))
      {
        game_state.set_gameOver(true);
        break;
      }
      else
      {
        game_state.set_gameOver(false);
        break;
      }
    }
  }//Horizontal check in the backwards direction

  if((i + 3) <= 6)
  {
    for(int k = i; k <= 6 ; k++)
    {
      if ((game_state.get_gameBoard(k, j)) == (game_state.get_gameBoard((k + 1), j)) == (game_state.get_gameBoard((k + 2), j)) == (game_state.get_gameBoard((k + 3), j)))
      {
        game_state.set_gameOver(true);
        break;
      }
      else
      {
        game_state.set_gameOver(false);
        break;
      }
    }
  }//Vertical check in the downwards direction

  if(((i - 3) >= 0) && ((j + 3) <= 6))
  {
    for (int k = i, p = j; k >= 0 && p <= 6; k--, p++)
    {
      if ((game_state.get_gameBoard(k, p)) == (game_state.get_gameBoard((k - 1),(p + 1))) == (game_state.get_gameBoard((k - 2),(p + 2))) == (game_state.get_gameBoard((k - 3),(p + 3))))
      {
        game_state.set_gameOver(true);
        break;
      }
      else
      {
        game_state.set_gameOver(false);
        break;
      }
    } 
  }//Diagonal Check - Bottom-Left to Top-Right

  if(((i + 3) <= 6) && ((j - 3) >= 0))
  {
    for (int k = i, p = j; k <= 6 && p >= 0; k++, p--)
    {
      if ((game_state.get_gameBoard(k, p)) == (game_state.get_gameBoard((k + 1),(p - 1))) == (game_state.get_gameBoard((k + 2),(p - 2))) == (game_state.get_gameBoard((k + 3),(p - 3))))
      {
        game_state.set_gameOver(true);
        break;
      }
      else
      {
        game_state.set_gameOver(false);
        break;
      }
    } 
  }//Diagonal Check - Top-Right to Bottom-Left

  if(((i - 3) >= 0) && ((j - 3) >= 0))
  {
    for (int k = i, p = j; k >= 0 && p >= 0; k--, p--)
    {
      if ((game_state.get_gameBoard(k, p)) == (game_state.get_gameBoard((k - 1),(p - 1))) == (game_state.get_gameBoard((k - 2),(p - 2))) == (game_state.get_gameBoard((k - 3),(p - 3))))
      {
        game_state.set_gameOver(true);
        break;
      }
      else
      {
        game_state.set_gameOver(false);
        break;
      }
    } 
  }//Diagonal Check - Bottom-Right to Top-Left

  if(((i + 3) <= 6) && ((j + 3) <= 6))
  {
    for (int k = i, p = j; k <= 6 && p <= 6; k++, p++)
    {
      if ((game_state.get_gameBoard(k, p)) == (game_state.get_gameBoard((k + 1),(p + 1))) == (game_state.get_gameBoard((k + 2),(p + 2))) == (game_state.get_gameBoard((k + 3),(p + 3))))
      {
        game_state.set_gameOver(true);
        break;
      }
      else
      {
        game_state.set_gameOver(false);
        break;
      }
    } 
  }//Diagonal Check - Bottom-Right to Bottom-Left

  // Change turn if move is valid,
  if((game_state.get_winner() == Empty) && (game_state.get_gameOver() == false) && (game_state.get_moveValid() == true) && (game_state.get_turn() == true))
  { 
    game_state.set_turn(false);
  }
  else if ((game_state.get_winner() == Empty) && (game_state.get_gameOver() == false) && (game_state.get_moveValid() == true) && (game_state.get_turn() == false))
  {
    game_state.set_turn(true);
  }

  else if((game_state.get_winner() == Empty) && (game_state.get_gameOver() == true) && (game_state.get_moveValid() == true) && (game_state.get_turn() == true))
  {
    game_state.set_turn(true);
  }

  else if ((game_state.get_winner() == Empty) && (game_state.get_gameOver() == true) && (game_state.get_moveValid() == true) && (game_state.get_turn() == false))
  {
    game_state.set_turn(true);
  }
  
  // Change winner
}