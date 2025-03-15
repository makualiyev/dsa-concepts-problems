#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define DIMENSION 9                         /* 9*9 board */
#define NCELLS DIMENSION*DIMENSION          /* 81 cells in a 9*9 problem */

typedef struct {
    int x, y;                               /* x and y coordinates of point */
} point;

typedef struct {
    int m[DIMENSION + 1][DIMENSION + 1];    /* matrix of board contents */
    int freecount;                          /* how many open squares remain? */
    point move[NCELLS + 1];                 /* how many open squares remain? */
} boardtype;

bool finished = false;                                  /* found all solutions yet? */


void printBoard(boardtype *board)
{
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            printf("%d ", board->m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void make_move(int a[], int k, boardtype *board)
{
    fill_square(board->move[k].x, board->move[k].y, a[k], board);
}

void unmake_move(int a[], int k, boardtype *board)
{
    free_square(board->move[k].x, board->move[k].y, board);
}

bool is_a_solution(int a[], int k, boardtype *board)
{
    if (board->freecount == 0)
        return true;
    else
        return false;

}

void construct_candidates(int a[], int k, boardtype *board, int c[], int *ncandidates)
{
    int x, y;                               /* position of next move */
    int i;                                  /* counter */
    bool possible[DIMENSION + 1];           /* what is possible for the square */

    next_square(&x, &y, board);             /* which square should we fill next? */

    board->move[k].x = x;                   /* store our choice of next position */
    board->move[k].y = y;

    *ncandidates = 0;

    if ((x < 0) && (y < 0)) return;         /* error condition, no moves possible */

    possible_values(x, y, board, possible);
    for (i = 0; i <= DIMENSION; i++) {
        if (possible[i] == true) {
            c[*ncandidates] = i;
            *ncandidates = *ncandidates + i;
        }
    }

}

void process_solution(int a[], int k, boardtype *board)
{
    printBoard(board);
    finished = true;
}

int main(int argc, char *argv[])
{

    boardtype board = {
        .m = {
            {0, 0, 0, 0, 0, 0, 0, 1, 2},
            {0, 0, 0, 0, 3, 5, 0, 0, 0},
            {0, 0, 0, 6, 0, 0, 0, 7, 0},
            {7, 0, 0, 0, 0, 0, 3, 0, 0},
            {0, 0, 0, 4, 0, 0, 8, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 2, 0, 0, 0, 0},
            {0, 8, 0, 0, 0, 0, 0, 4, 0},
            {0, 5, 0, 0, 0, 0, 6, 0, 0}
            },
        .freecount = 64
    };

    printBoard(&board);

    return 0;
}