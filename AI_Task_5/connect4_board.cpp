// Class definition for connect4_Board class
// Author:  Mahmoud Khaled
// Date:    17/12/2023
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

// Set the board
connect4_board::connect4_board () {
   n_rows = 6;
   n_cols = 7;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool connect4_board::update_board (int x, int y, char mark){
   // Only update if move is valid
    int i = 0;
   while (i < n_rows-1)
   {
      if(board[i+1][y] != 0 || i == n_rows-1)
         break;
      else
        i++;
   }
    
   if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[i][y] == 0)) {
    
      board[i][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void connect4_board::display_board() {
   for (int i: {0, 1, 2, 3, 4, 5}) {
      cout << "\n| ";
      for (int j: {0, 1, 2, 3, 4, 5, 6}) {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << " |";
      }
      cout << "\n----------------------------------------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.

bool connect4_board::is_winner() {

   for (int i = 0; i < n_rows-3; i++)
   {
      for (int j = 0; j < n_cols; j++)
      {
         if(board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j] && board[i+2][j] == board[i+3][j] && board[i][j] != 0)
            return true;
      }
   }
   
   
   for (int i = 0; i < n_rows; i++)
   {
      for (int j = 0; j < n_cols-3; j++)
      {
         if(board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j+2] == board[i][j+3] && board[i][j] != 0)
            return true;
      }
   }

   
   for (int i = 0; i < n_rows-3; i++)
   {
      for (int j = 0; j < n_cols-3; j++)
      {
         if(board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2] && board[i+2][j+2] == board[i+3][j+3] && board[i][j] != 0)
            return true;
      }
   }

   for (int i = 3; i < n_rows; i++)
   {
      for (int j = 0; j < n_cols-3; j++)
      {
         if(board[i][j] == board[i-1][j+1] && board[i-1][j+1] == board[i-2][j+2] && board[i-2][j+2] == board[i-3][j+3] && board[i][j] != 0)
            return true;
      }
   }

   return false;

}

// Return true if 9 moves are done and no winner
bool connect4_board::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool connect4_board::game_is_over () {
    return n_moves >= 42;
}