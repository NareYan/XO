#ifndef MAIN_H
 #define MAIN_H
 #include <stdio.h>
 #include <stdbool.h>

 int row, column, playersTurn, playersNumber;
 char playBoard[3][3];  
 void startTheGame();
 void computersMove(); 
 void playersMove(); 
 void printTheBoard(); 
 bool isBoardFull(); 
 bool isThereAWinner();
#endif 

