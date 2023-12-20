// Class definition for Pyramic_XO_App class
// Author:  Tarek Mohamed & Mahmoud Khaled
// Date:    11/12/2023
// Version: 2

#include <iostream>
#include "BoardGame_Classes.hpp"
//#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {

    int game;
    cout << "\nWelcome :)\n\nPlease select a game: \n1- Pyramid X O\n2- Connect 4\n3- 5x5 X O\n\nChoice: ";
    cin >> game;

    int choice;
    Player* players[2];
    players[0] = new Player(1, 'x');

    //cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "If you want to play with player 2 press 1 , Random computer player Press 2 , AI player press 3 : ";
    cin >> choice;
    cout << endl;
    

    if (game == 1)  // pyramid X_O
    {
        if (choice == 1)
            players[1] = new Player(2, 'o');
        else if(choice == 2)
            players[1] = new RandomPlayer('o', 5);     
        else 
            players[1] = new AI_player('o', 3);

        GameManager pyramid_x_o(new Pyramic_X_O_Board(), players);
        pyramid_x_o.run();
    }

    else if (game == 2)     // connect4
    {
        if (choice == 1)
            players[1] = new Player(2, 'o');
        else if(choice == 2)
            players[1] = new RandomPlayer('o', 7);
        else 
            players[1] = new AI_player('o', 7);

        GameManager c4_game(new connect4_board(), players);
        c4_game.run();
    }

    else if (game == 3)     // 5*5 X_O
    {
        if (choice == 1)
            players[1] = new Player(2, 'o');
        else if(choice == 2)
            players[1] = new RandomPlayer('o', 5);
        else 
            players[1] = new AI_player('o', 5);

        GameManager x_o_game(new X_O_Board(), players);
        x_o_game.run();
    }
    else
    {
        cout << "no game selected :(\n";
    }

    system("pause");

}
