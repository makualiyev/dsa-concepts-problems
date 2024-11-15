#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXCANDIDATES 100
typedef struct {
    int x, y;
} data;

/************************** */

bool finished = false;                                  /* found all solutions yet? */

/**
 * This boolean function This Boolean function tests whether the first k
 * elements of vector a from a complete solution for the given problem. The last
 * argument, input, allows us to pass general information into the routine. We
 * can use it to specify n—the size of a target solution. This makes sense when
 * constructing permutations or subsets of n elements, but other data may be
 * relevant when constructing variable-sized objects such as sequences of moves
 * in a game.
 */
void is_a_solution(int a[], int k, data input);

/**
 * This routine fills an array c with the complete set of possible candidates
 * for the kth position of a, given the contents of the first k − 1 positions.
 * The number of candidates returned in this array is denoted by ncandidates.
 * Again, input may be used to pass auxiliary information.
 */
void construct_candidates(int a[], int k, data input, int c[], int ncandidates);

/**
 * This routine prints, counts, or however processes a complete solution
 * once it is constructed.
 */
void process_solution(int a[], int k, data input);

/**
 * These routines enable us to modify a data structure in response to the latest
 * move, as well as clean up this data structure if we decide to take back the
 * move. Such a data structure could be rebuilt from scratch from the solution
 * vector a as needed, but this is inefficient when each move involves incremental
 * changes that can easily be undone.
 */
void make_move(int a[], int k, data input);

void unmake_move(int a[], int k, data input);

/**
 * main backtracking 
 */
void backtrack(int a[], int k, data input)
{
    int c[MAXCANDIDATES];                               /* candidates for next position */
    int ncandidates;                                    /* next position candidates count */
    int i;                                              /* counter */

    if (is_a_solution(a, k, input))
        process_solution(a, k, input);
    else {
        k = k + 1;
        construct_candidates(a, k, input, c, &ncandidates);
        for (i = 0; i < ncandidates; i++) {
            a[k] = c[i];
            make_move(a, k, input);
            backtrack(a, k, input);
            unmake_move(a, k, input);
            if (finished) return;                       /* terminate early */
        }
    }
}


int main(int argc, char *argv[])
{
    return 0;
}