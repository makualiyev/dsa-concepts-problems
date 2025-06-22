/*
    ARR
    i:    0   1   2   3   4   5   6   7   8   9         index of A
    A:    1   7   4   0   9   4   8   8   2   4         A array of random ints

    F:    1   1   3   1   1   3   2   2   1   3         frequencies
 */

#include <iostream>

using namespace std;

void count_sort(int A[], int N)
{
    // int F[10] = {0};            // initialization of an array full of zeros
    int F[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};    // explicit initialization
    for (int i = 0; i < N; i++)
    {
        F[A[i]]++;
    }
    int i = 0;
    for (int x = 0; x < 10; x++)                    //  all permutations (M) 
    {
        for (int k = 0; k < F[x]; k++)
        {
            A[i] = x;
            i++;
        }

    }
}

void generate_random_array(int A[], int N, int M)
{
    for (int i = 0; i < N; i++)
        A[i] = rand() % M;
}

void print_array(int A[], int N)
{
    for (int i = 0; i < N; i++)
        cout << A[i] << '\t';
    cout << '\n';
}


int main()
{
    int N = 10;
    int A[N];

    generate_random_array(A, N, 10);
    print_array(A, N);

    count_sort(A, N);
    print_array(A, N);

    return 0;
}