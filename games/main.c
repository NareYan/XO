#include "main.h"

int main(void)
{
    startTheGame(); 
    playersTurn = 1; 
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            playBoard[i][j] = ' ';
        }
    }
    printTheBoard();
            
    while(true)
    {
        if(playersNumber == 1 && playersTurn == 1)
        {
            playersMove();
            if(isThereAWinner())
                break;
            if(isBoardFull())
            {
                printf("It's a draw! \n");
                break; 
            }
        }
        else if(playersNumber == 1 && playersTurn == 2)
        {
            computersMove(); 
            printTheBoard();
            if(isThereAWinner())
                break;
            if(isBoardFull())
            {
                printf("It's a draw! \n");
                break; 
            }
        }

        else if(playersNumber == 2)
        {
            playersMove(); 
            if(isThereAWinner())
                break;
            if(isBoardFull())
            {
                printf("It's a draw! \n");
                break; 
            }
        }
        if(playersTurn == 1)
            playersTurn = 2; 
        else 
            playersTurn = 1; 

    }
    return 0; 

    
}