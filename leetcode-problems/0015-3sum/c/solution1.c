#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int **triplets = (int **)malloc(3 * sizeof(int *));
	if (triplets == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}

	for (int i = 0; i < 3; i++) {
		triplets[i] = (int *)malloc(3 * sizeof(int));
		if (triplets[i] == NULL) {
			printf("Memory allocation failed\n");
			// Free previously allocated memory before exiting
			for (int j = 0; j < i; j++) {
				free(triplets[j]);
			}
			free(triplets);
			return 1;
		}
	}

	triplets[0][0] = 1; triplets[0][1] = 2; triplets[0][2] = 3;
	triplets[1][0] = 4; triplets[1][1] = 5; triplets[1][2] = 6;
	triplets[2][0] = 7; triplets[2][1] = 8; triplets[2][2] = 9;

	for (int i = 0; i < 3; i++) {
        printf("Triplet %d: [%d, %d, %d]\n", i, triplets[i][0], triplets[i][1], triplets[i][2]);
    }

	for (int i = 0; i < 3; i++) {
        free(triplets[i]);
    }
    free(triplets);

	return 0;
}
