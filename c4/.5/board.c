#include "tictactoe.h"

#define MAX_WIN_ROWS    8

int *board[BOARD_SIZE][BOARD_SIZE];
int *winrows[MAX_WIN_ROWS][BOARD_SIZE];

// sets all board positions to zero and determines winnable rows
void initboard()
{
    int x, wr;

    for (x = wr = 0; x < BOARD_SIZE; x++)
    {
        winrows[BOARD_SIZE * 2][x]      = board[x][x];
        winrows[BOARD_SIZE * 2 + 1][x]  = board[BOARD_SIZE - (x + 1)][x];

        for (int y = 0; y < BOARD_SIZE; y++)
        {
            *board[y][x] = 0;

            winrows[wr][y] = board[y][x];
            winrows[wr + BOARD_SIZE][y] = board[x][y];
        }

        wr++;
    }
}

// prints board with current counter positions
void drawboard()
{
    for (int y = 0; y < (BOARD_SIZE * 2 - 1); y++)
    {
        for (int x = 0; x < BOARD_SIZE; x++)
        {
            if (y % 2 == 0)
                printf(" %c ", getcounter(*board[y / 2][x]));
            else
                printf("---");

            if (x < (BOARD_SIZE - 1))
                    putchar('|');
        }

        putchar('\n');
    }
}

// gets ASCII representation of int on board
int getcounter(int i)
{
    if (i == 1)
        return 'X';
    else if (i == -1)
        return 'O';
    else
        return ' ';
}

// puts a token at a specified position, returns -1 if position was already populated
int puttoken(int i, int pos[])
{
    int *boardpos = board[pos[0]][pos[1]];

    if (*boardpos != 0)
        return -1;

    *boardpos = i;
    return 0;
}

// determines if there is a winner on the board (returns 1 if X won or -1 if O won)
int haswinner()
{
    int wr = (BOARD_SIZE * 2) + 2;
    int i, j, sum;

    for (i = 0; i < wr; i++)
    {
        for (j = sum = 0; j < BOARD_SIZE; j++)
            sum += *winrows[i][j];

        if (sum == BOARD_SIZE)
            return 1;
        else if (sum == (BOARD_SIZE * -1))
            return -1;
    }

    return 0;
}
