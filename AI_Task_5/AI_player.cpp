// Class definition for AI_player  class
// Which is a computer player playing a stratigic move
// Author:  Mahmoud Khaled
// Date:    17/12/2023
// Version: 3
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
AI_player::AI_player (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}


// Generate a random move
void AI_player::get_move (int& x, int& y) 
{


    if(player_board->n_rows == 6)
    {
        for (int i = 0; i < player_board->n_rows; i++)
        {
            for (int j = 0; j < player_board->n_cols - 3; j++)
            {
                if(player_board->board[i][j] == 'O' && player_board->board[i][j+1] == 'O' && player_board->board[i][j+2] == 'O'  && player_board->board[i][j+3] == 0)
                {
                    x = i;
                    y = j+3;
                    //cout << "////" << i << "///" << j+2 << "////";
                    return;
                }
            }
            
        }

        for (int i = 0; i < player_board->n_rows - 3; i++)
        {
            for (int j = 0; j < player_board->n_cols; j++)
            {
                if(player_board->board[i][j] == 'O' && player_board->board[i+1][j] == 'O' && player_board->board[i+2][j] == 'O' && player_board->board[i+3][j] == 0)
                {
                    x = i+3;
                    y = j;
                    //cout << "////" << i+2 << "///" << j << "////";
                    return;
                }
                
            }
            
        }

        

        for (int i = 0; i < player_board->n_rows; i++)
        {
            for (int j = 0; j < player_board->n_cols - 3; j++)
            {
                if(player_board->board[i][j] == 0 && player_board->board[i][j+1] == 'O' && player_board->board[i][j+2] == 'O' && player_board->board[i][j+3] == 'O')
                {
                    x = i;
                    y = j;
                    //cout << "////" << i << "///" << j+2 << "////";
                    return;
                }
            }
            
        }

        for (int i = 0; i < player_board->n_rows - 3; i++)
        {
            for (int j = 0; j < player_board->n_cols; j++)
            {
                if(player_board->board[i][j] == 0 && player_board->board[i+1][j] == 'O' && player_board->board[i+2][j] == 'O' && player_board->board[i+3][j] == 'O')
                {
                    x = i;
                    y = j;
                    //cout << "////" << i+2 << "///" << j << "////";
                    return;
                }          
            }
            
        }

        for (int i = 0; i < player_board->n_rows; i++)
        {
            for (int j = 0; j < player_board->n_cols - 3; j++)
            {
                if(player_board->board[i][j] == 'X' && player_board->board[i][j+1] == 'X' && player_board->board[i][j+2] == 'X'  && player_board->board[i][j+3] == 0)
                {
                    x = i;
                    y = j+3;
                    //cout << "////" << i << "///" << j+2 << "////";
                    return;
                }
            }
            
        }

        for (int i = 0; i < player_board->n_rows - 3; i++)
        {
            for (int j = 0; j < player_board->n_cols; j++)
            {
                if(player_board->board[i][j] == 'X' && player_board->board[i+1][j] == 'X' && player_board->board[i+2][j] == 'X' && player_board->board[i+3][j] == 0)
                {
                    x = i+3;
                    y = j;
                    //cout << "////" << i+2 << "///" << j << "////";
                    return;
                }
                
            }
            
        }

        

        for (int i = 0; i < player_board->n_rows; i++)
        {
            for (int j = 0; j < player_board->n_cols - 3; j++)
            {
                if(player_board->board[i][j] == 0 && player_board->board[i][j+1] == 'X' && player_board->board[i][j+2] == 'X' && player_board->board[i][j+3] == 'X')
                {
                    x = i;
                    y = j;
                    //cout << "////" << i << "///" << j+2 << "////";
                    return;
                }
            }
            
        }

        for (int i = 0; i < player_board->n_rows - 3; i++)
        {
            for (int j = 0; j < player_board->n_cols; j++)
            {
                if(player_board->board[i][j] == 0 && player_board->board[i+1][j] == 'X' && player_board->board[i+2][j] == 'X' && player_board->board[i+3][j] == 'X')
                {
                    x = i;
                    y = j;
                    //cout << "////" << i+2 << "///" << j << "////";
                    return;
                }          
            }
            
        }
    }
    
    // Check prime Diagonal for winning
    //--------------------------------------------------------------------------------------------------------------------------

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = 0; j < player_board->n_cols - 2; j++)
        {
            if(player_board->board[i][j] == 'O' && player_board->board[i+1][j+1] == 'O' && player_board->board[i+2][j+2] == 0)
            {
                x = i+2;
                y = j+2;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = 0; j < player_board->n_cols - 2; j++)
        {
            if(player_board->board[i][j] == 'O' && player_board->board[i+1][j+1] == 0 && player_board->board[i+2][j+2] == 'O')
            {
                x = i+1;
                y = j+1;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = 0; j < player_board->n_cols - 2; j++)
        {
            if(player_board->board[i][j] == 0 && player_board->board[i+1][j+1] == 'O' && player_board->board[i+2][j+2] == 'O')
            {
                x = i;
                y = j;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    // Check off Diagonal for winning
    //--------------------------------------------------------------------------------------------------------------------------

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = player_board->n_cols - 1; j > 1; j--)
        {
            if(player_board->board[i][j] == 'O' && player_board->board[i+1][j-1] == 'O' && player_board->board[i+2][j-2] == 0)
            {
                x = i+2;
                y = j-2;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = player_board->n_cols - 1; j > 1; j--)
        {
            if(player_board->board[i][j] == 'O' && player_board->board[i+1][j-1] == 0 && player_board->board[i+2][j-2] == 'O')
            {
                x = i+1;
                y = j-1;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = player_board->n_cols - 1; j > 1; j--)
        {
            if(player_board->board[i][j] == 0 && player_board->board[i+1][j-1] == 'O' && player_board->board[i+2][j-2] == 'O')
            {
                x = i;
                y = j;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }
    
    //---------------------------------------------------------------------------------------------------------------------------


    
    for (int i = 0; i < player_board->n_rows; i++)
    {
        for (int j = 0; j < player_board->n_cols - 2; j++)
        {
            if(player_board->board[i][j] == 'O' && player_board->board[i][j+1] == 'O' && player_board->board[i][j+2] == 0)
            {
                x = i;
                y = j+2;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = 0; j < player_board->n_cols; j++)
        {
            if(player_board->board[i][j] == 'O' && player_board->board[i+1][j] == 'O' && player_board->board[i+2][j] == 0)
            {
                x = i+2;
                y = j;
                //cout << "////" << i+2 << "///" << j << "////";
                return;
            }
            
        }
        
    }

    for (int i = 0; i < player_board->n_rows; i++)
    {
        for (int j = 0; j < player_board->n_cols - 2; j++)
        {
            if(player_board->board[i][j] == 'O' && player_board->board[i][j+1] == 0 && player_board->board[i][j+2] == 'O')
            {
                x = i;
                y = j+1;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = 0; j < player_board->n_cols; j++)
        {
            if(player_board->board[i][j] == 'O' && player_board->board[i+1][j] == 0 && player_board->board[i+2][j] == 'O')
            {
                x = i+1;
                y = j;
                //cout << "////" << i+2 << "///" << j << "////";
                return;
            }          
        }
        
    }

    for (int i = 0; i < player_board->n_rows; i++)
    {
        for (int j = 0; j < player_board->n_cols - 2; j++)
        {
            if(player_board->board[i][j] == 0 && player_board->board[i][j+1] == 'O' && player_board->board[i][j+2] == 'O')
            {
                x = i;
                y = j;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = 0; j < player_board->n_cols; j++)
        {
            if(player_board->board[i][j] == 0 && player_board->board[i+1][j] == 'O' && player_board->board[i+2][j] == 'O')
            {
                x = i;
                y = j;
                //cout << "////" << i+2 << "///" << j << "////";
                return;
            }          
        }
        
    }

    //--------------------------------------------------------------------------------------------------------------------------



    //checking prime diagonal for not lossing
    //---------------------------------------------------------------------------------------------------------------------------
    
    
    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = 0; j < player_board->n_cols - 2; j++)
        {
            if(player_board->board[i][j] == 'X' && player_board->board[i+1][j+1] == 'X' && player_board->board[i+2][j+2] == 0)
            {
                x = i+2;
                y = j+2;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = 0; j < player_board->n_cols - 2; j++)
        {
            if(player_board->board[i][j] == 'X' && player_board->board[i+1][j+1] == 0 && player_board->board[i+2][j+2] == 'X')
            {
                x = i+1;
                y = j+1;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = 0; j < player_board->n_cols - 2; j++)
        {
            if(player_board->board[i][j] == 0 && player_board->board[i+1][j+1] == 'X' && player_board->board[i+2][j+2] == 'X')
            {
                x = i;
                y = j;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    // checking off diagonal for not lossing
    //---------------------------------------------------------------------------------------------------------------------------

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = player_board->n_cols - 1; j > 1; j--)
        {
            if(player_board->board[i][j] == 'X' && player_board->board[i+1][j-1] == 'X' && player_board->board[i+2][j-2] == 0)
            {
                x = i+2;
                y = j-2;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = player_board->n_cols - 1; j > 1; j--)
        {
            if(player_board->board[i][j] == 'X' && player_board->board[i+1][j-1] == 0 && player_board->board[i+2][j-2] == 'X')
            {
                x = i+1;
                y = j-1;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = player_board->n_cols - 1; j > 1; j--)
        {
            if(player_board->board[i][j] == 0 && player_board->board[i+1][j-1] == 'X' && player_board->board[i+2][j-2] == 'X')
            {
                x = i;
                y = j;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    //---------------------------------------------------------------------------------------------------------------------------

    for (int i = 0; i < player_board->n_rows; i++)
    {
        for (int j = 0; j < player_board->n_cols - 2; j++)
        {
            if(player_board->board[i][j] == 'X' && player_board->board[i][j+1] == 'X' && player_board->board[i][j+2] == 0)
            {
                cout << "////" << 1 << "/////";
                x = i;
                y = j+2;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = 0; j < player_board->n_cols; j++)
        {
            if(player_board->board[i][j] == 'X' && player_board->board[i+1][j] == 'X' && player_board->board[i+2][j] == 0)
            {
                cout << "////" << 2 << "/////";
                x = i+2;
                y = j;
                //cout << "////" << i+2 << "///" << j << "////";
                return;
            }
            
        }
        
    }

    for (int i = 0; i < player_board->n_rows; i++)
    {
        for (int j = 0; j < player_board->n_cols - 2; j++)
        {
            if(player_board->board[i][j] == 'X' && player_board->board[i][j+1] == 0 && player_board->board[i][j+2] == 'X')
            {
                cout << "////" << 3 << "/////";
                x = i;
                y = j+1;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }
        
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = 0; j < player_board->n_cols; j++)
        {
            if(player_board->board[i][j] == 'X' && player_board->board[i+1][j] == 0 && player_board->board[i+2][j] == 'X')
            {
                cout << "////" << 4 << "/////";
                x = i+1;
                y = j;
                //cout << "////" << i+2 << "///" << j << "////";
                return;
            }          
        }  
    }

    for (int i = 0; i < player_board->n_rows; i++)
    {
        for (int j = 0; j < player_board->n_cols - 2; j++)
        {
            if(player_board->board[i][j] == 0 && player_board->board[i][j+1] == 'X' && player_board->board[i][j+2] == 'X')
            {
                cout << "////" << 5 << "/////";
                x = i;
                y = j;
                //cout << "////" << i << "///" << j+2 << "////";
                return;
            }
        }  
    }

    for (int i = 0; i < player_board->n_rows - 2; i++)
    {
        for (int j = 0; j < player_board->n_cols; j++)
        {
            if(player_board->board[i][j] == 0 && player_board->board[i+1][j] == 'X' && player_board->board[i+2][j] == 'X')
            {
                cout << "////" << 6 << "/////";
                x = i;
                y = j;
                //cout << "////" << i+2 << "///" << j << "////";
                return;
            }
        }
        
    }

    if(player_board->board[1][1] == 0)
    {
        x = 1;
        y = 1;
        return;
    }


    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    
}
