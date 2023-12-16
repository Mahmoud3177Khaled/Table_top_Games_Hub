// Class definition for Tic_Tac_Toe_5_5 (Game 3)
// Author:  Abdullah Mahmoud Anwer     
// Date:    16/12/2023
// Version: 3

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>

using namespace std;

class Board {
protected:
    int n_rows, n_cols;
    char** board;
    int n_moves = 0;

public:
    virtual bool update_board(int x, int y, char symbol) = 0;
    virtual bool is_winner() = 0;
    virtual bool is_draw() = 0;
    virtual void display_board() = 0;
    virtual bool game_is_over() = 0;
    virtual char get_winner() = 0;
};

class X_O_Board : public Board {
public:
    X_O_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    char get_winner();
};

class Player {
protected:
    string name;
    char symbol;
    int moves_made;

public:
    Player(char symbol);
    Player(int order, char symbol);
    virtual void get_move(int& x, int& y);
    string to_string();
    char get_symbol();
    void increment_moves();
    int get_moves_made();
};

class RandomPlayer : public Player {
protected:
    int dimension;

public:
    RandomPlayer(char symbol, int dimension);
    void get_move(int& x, int& y);
};

class GameManager {
private:
    Board* boardPtr;
    Player* players[2];

public:
    GameManager(Board*, Player* playerPtr[2]);
    void run();
};

X_O_Board::X_O_Board() {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
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
    } else
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
    if(n_moves <24)
    {
        return false;
    }
    int x_count=0, o_count=0;
    for(int i =0; i<5; i++)
    {
        for(int j = 0; j<5; j++)
        {
            if((i+2)<=4 && board[i][j]==board[i+1][j] &&board[i][j] == board[i+2][j])
            {
                if(board[i][j] =='X')
                {
                    x_count++;
                }
                else if(board[i][j] =='O')
                {
                    o_count++;
                }
            }
            if((i-2)>=0 && board[i][j]==board[i-1][j] &&board[i][j] == board[i-2][j])
            {
                if(board[i][j] =='X')
                {
                    x_count++;
                }
                else if(board[i][j] =='O')
                {
                    o_count++;
                }
            }
            if((j+2)<=4 && board[i][j]==board[i][j+1] &&board[i][j] == board[i][j+2])
            {
                if(board[i][j] =='X')
                {
                    x_count++;
                }
                else if(board[i][j] =='O')
                {
                    o_count++;
                }
            }
            if((j-2)>=0 && board[i][j]==board[i][j-1] &&board[i][j] == board[i][j-2])
            {
                if(board[i][j] =='X')
                {
                    x_count++;
                }
                else if(board[i][j] =='O')
                {
                    o_count++;
                }
            }
            if((j+2) <=4 && (i+2)<=4 && board[i][j]==board[i+1][j+1] &&board[i][j] == board[i+2][j+2])
            {
                if(board[i][j] =='X')
                {
                    x_count++;
                }
                else if(board[i][j] =='O')
                {
                    o_count++;
                }
            }
            if((j-2)>=0 && (i-2)>=0&& board[i][j]==board[i-1][j-1] &&board[i][j] == board[i-2][j-2])
            {
                if(board[i][j] =='X')
                {
                    x_count++;
                }
                else if(board[i][j] =='O')
                {
                    o_count++;
                }
            }
            if((j-2) >=0 && (i+2) <=4 && board[i][j]==board[i+1][j-1] &&board[i][j] == board[i+2][j-2])
            {
                if(board[i][j] =='X')
                {
                    x_count++;
                }
                else if(board[i][j] =='O')
                {
                    o_count++;
                }
            }
            if((i-2)>=0 && (j+2)<=4 && board[i][j]==board[i-1][j+1] &&board[i][j] == board[i-2][j+2])
            {
                if(board[i][j] =='X')
                {
                    x_count++;
                }
                else if(board[i][j] =='O')
                {
                    o_count++;
                }
            }
        }
    }

    if(x_count >o_count)
    {
        cout << "the player X is the winner" <<endl;
    }
    else if(x_count <o_count)
    {
        cout << "the player O is the winner" <<endl;
    }
    else
    {
        cout << "Draw!!" <<endl;
    }
    return false;


}


bool X_O_Board::is_draw() {
    return (n_moves == 24 && !is_winner());
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
                } else if (board[i][j] == 'O') {
                    o_count++;
                }
            }
        }
        if (x_count > o_count) {
            return 'X';
        } else if (o_count > x_count) {
            return 'O';
        } else {
            return ' ';
        }
    } else {
        return ' ';
    }
}

GameManager::GameManager(Board* bPtr, Player* playerPtr[2]) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i = 0; i < 2; i++) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->game_is_over()) {
                char winner = boardPtr->get_winner();
                if (winner != ' ') {
                    cout << "Player " << winner << " wins\n";
                } else {
                    cout << "Draw!\n";
                }
                return;
            }
        }
    }
}

RandomPlayer::RandomPlayer(char symbol, int dimension) : Player(symbol) {
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

void RandomPlayer::get_move(int& x, int& y) {
    x = (int)(rand() / (RAND_MAX + 1.0) * dimension);
    y = (int)(rand() / (RAND_MAX + 1.0) * dimension);
}

Player::Player(char symbol) {
    this->symbol = symbol;
    this->moves_made = 0;
}

Player::Player(int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
    this->moves_made = 0;
}

void Player::get_move(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to " << 4 << ") separated by spaces: ";
    cin >> x >> y;
    moves_made++;
}

string Player::to_string() {
    return "Player: " + name;
}

char Player::get_symbol() {
    return symbol;
}

void Player::increment_moves() {
    moves_made++;
}

int Player::get_moves_made() {
    return moves_made;
}

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player(1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player(2, 'o');
    else
        players[1] = new RandomPlayer('o', 5);

    GameManager x_o_game(new X_O_Board(), players);
    x_o_game.run();
    system("pause");
}
