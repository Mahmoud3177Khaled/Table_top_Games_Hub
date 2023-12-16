#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

X_O_Board::X_O_Board() {
    n_rows = n_cols = 5;
    board = new char* [n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool X_O_Board::update_board(int x, int y, char mark) {
    if (!(x < 0 || x >= n_rows || y < 0 || y >= n_cols) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void X_O_Board::display_board() {
    for (int i : {0, 1, 2, 3, 4}) {
        cout << endl;
        for (int j : {0, 1, 2, 3, 4}) {
            cout << "[" << i << "," << j << "]";
            cout << setw(2) << "[" << board[i][j] << "]" << " |";
        }
        cout << "\n-------------------------------------------------------";
    }
    cout << endl;
}

bool X_O_Board::is_winner() {
    if (n_moves < 24)
    {
        return false;
    }
    int x_count = 0, o_count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((i + 2) <= 4 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j])
            {
                if (board[i][j] == 'X')
                {
                    x_count++;
                }
                else if (board[i][j] == 'O')
                {
                    o_count++;
                }
            }
            if ((i - 2) >= 0 && board[i][j] == board[i - 1][j] && board[i][j] == board[i - 2][j])
            {
                if (board[i][j] == 'X')
                {
                    x_count++;
                }
                else if (board[i][j] == 'O')
                {
                    o_count++;
                }
            }
            if ((j + 2) <= 4 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
            {
                if (board[i][j] == 'X')
                {
                    x_count++;
                }
                else if (board[i][j] == 'O')
                {
                    o_count++;
                }
            }
            if ((j - 2) >= 0 && board[i][j] == board[i][j - 1] && board[i][j] == board[i][j - 2])
            {
                if (board[i][j] == 'X')
                {
                    x_count++;
                }
                else if (board[i][j] == 'O')
                {
                    o_count++;
                }
            }
            if ((j + 2) <= 4 && (i + 2) <= 4 && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2])
            {
                if (board[i][j] == 'X')
                {
                    x_count++;
                }
                else if (board[i][j] == 'O')
                {
                    o_count++;
                }
            }
            if ((j - 2) >= 0 && (i - 2) >= 0 && board[i][j] == board[i - 1][j - 1] && board[i][j] == board[i - 2][j - 2])
            {
                if (board[i][j] == 'X')
                {
                    x_count++;
                }
                else if (board[i][j] == 'O')
                {
                    o_count++;
                }
            }
            if ((j - 2) >= 0 && (i + 2) <= 4 && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2])
            {
                if (board[i][j] == 'X')
                {
                    x_count++;
                }
                else if (board[i][j] == 'O')
                {
                    o_count++;
                }
            }
            if ((i - 2) >= 0 && (j + 2) <= 4 && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2])
            {
                if (board[i][j] == 'X')
                {
                    x_count++;
                }
                else if (board[i][j] == 'O')
                {
                    o_count++;
                }
            }
        }
    }

    if (x_count > o_count)
    {
        cout << "the player X is the winner" << endl;
    }
    else if (x_count < o_count)
    {
        cout << "the player O is the winner" << endl;
    }
    else
    {
        cout << "Draw!!" << endl;
    }
    return false;


}


bool X_O_Board::is_draw() {
    return false;
}

bool X_O_Board::game_is_over() {
    return n_moves >= 24;
}


char X_O_Board::get_winner() {
    if (is_winner()) {
        int x_count = 0, o_count = 0;
        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                if (board[i][j] == 'X') {
                    x_count++;
                }
                else if (board[i][j] == 'O') {
                    o_count++;
                }
            }
        }
        if (x_count > o_count) {
            return 'X';
        }
        else if (o_count > x_count) {
            return 'O';
        }
        else {
            return ' ';
        }
    }
    else {
        return ' ';
    }
}
