// Class definition for Pyramic_XO_App class
// Author:  Tarek Mohamed
// Date:    11/12/2023
// Version: 2
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "BoardGame_Classes.hpp"
//#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
Pyramic_X_O_Board::Pyramic_X_O_Board()
{
    n_rows = 3;
    n_cols = 5;
    board = new char* [n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = '.'; // this cell is empty
    }

    // if board[i][j] = '.'  -> empty cell
    // if board[i][j] = '#' -> this cell out of the pyramid 
    for (int i = 1; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            if (i == 1 && (j < 1 || j > 3))
                board[i][j] = '#';
            else if (i == 2 && j != 2)
                board[i][j] = '#';
        }
    }
}

bool Pyramic_X_O_Board::update_board(int x, int y, char mark)
{
    // not valid move
    if (x >= n_rows || x < 0 || y >= n_cols || y < 0 || board[x][y] != '.')
        return false;
    board[x][y] = toupper(mark);
    n_moves++;
    return true;
}

void Pyramic_X_O_Board::display_board()
{
    
    for (int i = n_rows-1; i >= 0 ; i--)
    {
        cout << "    | ";
        for (int j = 0; j < n_cols; j++)
        {
            if (board[i][j] == '#')
                cout << ' ' << ' ';
            else
                cout << board[i][j] << ' ';
        }
        cout << " | " <<  endl;
    }
    cout << endl ;
}

bool Pyramic_X_O_Board::is_winner()
{
    // check first and second row (row[0] , row[1])
    for (int j = 0; j < 2; j++)
    {
        int c = 1;
        for (int i = 1; i < n_cols; i++)
        {
            if (board[j][i] == board[j][i - 1] && board[j][i] != '.')
                c++;
            else
                c = 1;
            if (c == 3)
                return true;
        }
    }

    // check the col[2]
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] != '.')
        return true;
    //check diags 
    if (board[2][2] == board[1][1] && board[1][1] == board[0][0] && board[2][2] != '.')
        return true;
    if (board[2][2] == board[1][3] && board[1][3] == board[0][4] && board[2][2] != '.')
        return true;

    return false;
}

bool Pyramic_X_O_Board::is_draw()
{
    return (n_moves == 9 && !is_winner());
}

bool Pyramic_X_O_Board::game_is_over()
{
    return (n_moves >= 9);
}

Pyramic_X_O_Board::~Pyramic_X_O_Board()
{
    for (int i = 0; i < n_rows; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

/*
X_O_Board::X_O_Board () {
   n_rows = n_cols = 3;
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
bool X_O_Board::update_board (int x, int y, char mark){
   // Only update if move is valid
   if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board() {
   for (int i: {0,1,2}) {
      cout << "\n| ";
      for (int j: {0,1,2}) {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << " |";
      }
      cout << "\n-----------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O_Board::is_winner() {
    char row_win[3], col_win[3], diag_win[2];
    for (int i:{0,1,2}) {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i:{0,1,2}) {
        if ( (row_win[i] && (row_win[i] == board[i][0])) ||
             (col_win[i] && (col_win[i] == board[0][i])) )
            {return true;}
    }
    if ((diag_win[0] && diag_win[0] == board[1][1]) ||
        (diag_win[1] && diag_win[1] == board[1][1]))
        {return true;}
    return false;
}

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over () {
    return n_moves >= 9;
}
*/
