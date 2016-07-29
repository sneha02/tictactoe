//Program to create a TICTACTOE Game

#include <stdio.h>
#define EMPTY (char)222

void clearBoard(char b[][3], int r, int c)
{
    int i, j;
    for(i =0 ; i< r; i++)
    {
        for(j =0; j< c; j++)
        {
            b[i][j] = EMPTY;
        }
    }
}


void printBoard(char b[][3], int r, int c)
{
    int i, j;

    for(i =0 ; i< r; i++)
    {
        printf("\n\n");
        for(j =0 ; j< c; j++)
        {
            printf("%5c", b[i][j]);
        }
    }
    printf("\n");
}


int authenticateMove(char b[][3], int r, int c, int i, int j)
{
    if(i < 0 || i > 2)
        return 0;
    if(j < 0 || j > 2)
        return 0;
    if(b[i][j] == EMPTY)
        return 1;
    else
        return 0;
}

int checkWins(char b[][3], int r, int c, char symbol)
{
    int i;
    for(i =0 ; i< r; i++)
    {
        if(b[i][0] == symbol && b[i][1] == symbol && b[i][2] == symbol)
            return 1;
    }

    for(i =0 ; i< r; i++)
    {
        if(b[0][i] == symbol && b[1][i] == symbol && b[2][i] == symbol)
            return 1;
    }

    if(b[0][0] == symbol && b[1][1] == symbol && b[2][2] == symbol)
        return 1;

    if(b[0][2] == symbol && b[1][1] == symbol && b[2][0] == symbol)
        return 1;

    return 0;

}

int checkIsGameOver(char b[][3], int r, int c)
{
    int i, j;
    for(i =0 ; i< r; i++)
        for(j =0 ; j < c; j++)
            if(b[i][j] == EMPTY)
                return 0;//false
    return 1;
}

void play(char b[][3], int r, int c)
{
    char symbol;
    int i, j, flag;

    printf("\n Welcome To TIC TAC TOE");
    clearBoard(b,r,c);
    do
    {
        printBoard(b,r,c);

        do
        {
            symbol = 'X';
            printf("\n Player 1 plays ");
            printf("\n Enter row coordinate [0-2] : ");
            scanf("%d", &i);
            printf("\n Enter col coordinate [0-2] : ");
            scanf("%d", &j);

            flag = authenticateMove(b, r, c, i, j);

        }while(flag == 0);

        //update the board
        b[i][j] = symbol;
        printBoard(b, r, c);

        flag = checkWins(b, r, c, symbol);
        if(flag == 1)
        {
            printf("\n Player 1 WINS");
            return;//terminate the function
        }

        flag = checkIsGameOver(b,r,c);
        if(flag == 1)
        {
            printf("\n Its a DRAW");
            return;//terminate the function
        }

        //player 2
        do
        {
            symbol = 'O';
            printf("\n Player 2 plays ");
            printf("\n Enter row coordinate [0-2] : ");
            scanf("%d", &i);
            printf("\n Enter col coordinate [0-2] : ");
            scanf("%d", &j);

            flag = authenticateMove(b, r, c, i, j);

        }while(flag == 0);

        //update the board
        b[i][j] = symbol;
        printBoard(b, r, c);

        flag = checkWins(b, r, c, symbol);
        if(flag == 1)
        {
            printf("\n Player 2 WINS");
            return;//terminate the function
        }

        flag = checkIsGameOver(b,r,c);
        if(flag == 1)
        {
            printf("\n Its a DRAW");
            return;//terminate the function
        }
    }while(flag ==0);
}


int main()
{
    char board[3][3];
    char ch;
    do
    {
        play(board, 3, 3);
        printf("\n Do you want to play again (y/n) ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y' || ch == 'Y');

    return 0;
}//main
