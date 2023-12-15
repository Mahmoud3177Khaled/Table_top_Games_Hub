// Class definition for Pyramic_XO_App class
// Author:  Tarek Mohamed
// Date:    11/12/2023
// Version: 2

#include <iostream>
#include "BoardGame_Classes.hpp"
//#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player(1, 'x');

    //cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "If you want to play with computer press 1 , else Press 2  : ";
    cin >> choice;
    cout << endl;
    if (choice != 1)
        players[1] = new Player(2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer('o', 5);

    GameManager x_o_game(new Pyramic_X_O_Board(), players);
    x_o_game.run();
    system("pause");
}
