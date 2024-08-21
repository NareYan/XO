#include "main.h"
void startTheGame()
{
    printf("Welcome! Enter the number of players! \n"); 
    scanf("%d", &playersNumber);
    if (playersNumber == 1)
        printf("Player 1 is X. \nComputer is O. \n");
    else if (playersNumber == 2)
        printf("Player 1 is X. \nPlayer 2 is O. \n");
    else 
    {    
        printf("Invalid number of players!"); 
        return; 
    }
        
}

void printTheBoard()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (j < 2)
                printf(" %c |", playBoard[i][j]);
            else
                printf(" %c ", playBoard[i][j]); 

        }
        printf("\n"); 
    } 
    return;
}

void playersMove()
{
    if (playersTurn == 1 || playersTurn == 2)
    {
        printf("Player %d, enter the row and the column. \n", playersTurn); 
        scanf("%d %d", &row, &column); 
        if (row < 0 || row > 2 || column < 0 || column > 2)
        {   
            printf("Invalid row and column. Try again! \n"); 
            playersMove(); 
            return; 
        }
        else if (playBoard[row][column] != ' ')
        {
            printf("The spot is taken. Try again! \n"); 
            playersMove(); 
            return; 
        }
        if (playersTurn == 1)
            playBoard[row][column] = 'X'; 
        else if(playersTurn == 2)
            playBoard[row][column] = 'O'; 
        printTheBoard(); 
        printf("\n \n"); 

    }
}

bool isBoardFull()
{
    int count = 0; 
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (playBoard[i][j] == 'X' || playBoard[i][j] == 'O')
                count++; 
        }
    }
    if (count == 9)
        return true;
    return false; 
}

bool isThereAWinner()
{
    for (int i = 0; i < 3; i++)
        if (playBoard[i][0] != ' ' && playBoard[i][0] == playBoard[i][1] && playBoard[i][0] == playBoard[i][2])
        {
            printf("Player %d won! \n", playersTurn); 
            return true; 
        }

    for (int i = 0; i < 3; i++)
        if (playBoard[0][i] != ' ' && playBoard[0][i] == playBoard[1][i] && playBoard[0][i] == playBoard[2][i])
        {
            printf("Player %d won! \n", playersTurn);
            return true; 
        }

    if (playBoard[0][0] != ' ' && playBoard[0][0] == playBoard[1][1] && playBoard[0][0] == playBoard[2][2])
    {
        printf("Player %d won! \n", playersTurn);
        return true; 
    }

    if (playBoard[0][2] != ' ' && playBoard[0][2] == playBoard[1][1] && playBoard[0][2] == playBoard[2][0])
    {
        printf("Player %d won! \n", playersTurn);
        return true; 
    }
    
    return false; 
      
}

void computersMove()
{
    if(playersNumber == 1 && playersTurn == 2)
    {
        char marks[2] = {'X', 'O'};
        {
            for (int j = 0; j < 2; ++j)
            {
                
                for (int i = 0; i < 3; ++i)
                {
                    if(playBoard[i][0] == marks[j] && playBoard[i][0] == playBoard[i][1] && playBoard[i][2] == ' ')
                    {   
                        playBoard[i][2] = 'O'; 
                        return;
                    }
                    else if(playBoard[i][0] == marks[j] && playBoard[i][0] == playBoard[i][2] && playBoard[i][1] == ' ')
                    {
                        playBoard[i][1] = 'O'; 
                        return;
                    }
                    else if(playBoard[i][1] == marks[j] && playBoard[i][1] == playBoard[i][2] && playBoard[i][0] == ' ')
                    {
                        playBoard[i][0] = 'O'; 
                        return;
                    }
                }

                for (int i = 0; i < 3; ++i)
                {
                    if (playBoard[0][i] == marks[j] && playBoard[0][i] == playBoard[1][i] && playBoard[2][i] == ' ')
                    {
                        playBoard[2][i] = 'O';
                        return;
                    }
                    else if (playBoard[0][i] == marks[j] && playBoard[0][i] == playBoard[2][i] && playBoard[1][i] == ' ')
                    {
                        playBoard[1][i] = 'O';
                        return; 
                    }
                    else if (playBoard[1][i] == marks[j] && playBoard[1][i] == playBoard[2][i] && playBoard[0][i] == ' ')
                    {
                        playBoard[0][i] = 'O';
                        return; 
                    }
                }

                if(playBoard[0][0] == marks[j] && playBoard[0][0] == playBoard[1][1] && playBoard[2][2] == ' ')
                {
                    playBoard[2][2] = 'O';
                    return; 
                }
                else if(playBoard[0][0] == marks[j] && playBoard[0][0] == playBoard[2][2] && playBoard[1][1] == ' ')
                {
                    playBoard[1][1] = 'O';
                    return; 
                }
                else if(playBoard[1][1] == marks[j] && playBoard[1][1] == playBoard[2][2] && playBoard[0][0] == ' ')
                {
                    playBoard[0][0] = 'O';
                    return; 
                }

                if(playBoard[0][2] == marks[j] && playBoard[0][2] == playBoard[1][1] && playBoard[2][0] == ' ')
                {
                    playBoard[2][0] = 'O';
                    return;
                }
                else if(playBoard[0][2] == marks[j] && playBoard[0][2] == playBoard[2][0] && playBoard[1][1] == ' ')
                {
                    playBoard[1][1] = 'O';
                    return;
                }
                else if(playBoard[1][1] == marks[j] && playBoard[1][1] == playBoard[2][0] && playBoard[0][2] == ' ')
                {
                    playBoard[0][2] = 'O';
                    return;
                }

                for(int i = 0; i < 3; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        if(playBoard[i][j] == ' ')
                        {
                            playBoard[i][j] = 'O'; 
                            return; 
                        }
                    }
                }
            }
        }
    }
}




