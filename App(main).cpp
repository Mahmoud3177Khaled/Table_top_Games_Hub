// Class definition for Pyramic_XO_App class
// Author:  Tarek Mohamed
// Date:    11/12/2023
// Version: 2

#include <iostream>
#include "BoardGame_Classes.hpp"
//#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {

    int game;
    cout << "\nWelcome :)\n\nPlease select a game: \n1- Pyramid X O\n2- Connect 4\n3- 5x5 X O\nChoice: ";
    cin >> game;

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


    if(game == 1)
    {
        GameManager pyramid_x_o(new Pyramic_X_O_Board(), players);
        pyramid_x_o.run();
    }
    else if(game == 2)
    {
        GameManager c4_game(new connect4_board(), players);
        c4_game.run();
    }
    else if(game == 3)
    {

    }
    else
    {
        cout << "no game selected :(\n";
    }

    system("pause");

}
