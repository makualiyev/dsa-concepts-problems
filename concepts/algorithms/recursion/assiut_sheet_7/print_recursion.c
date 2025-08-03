/**
 * Given a number N. Print "I love Recursion" N times.
 */

#include <stdio.h>
#include <stdlib.h>

void printRecursion(int n)
{
	if (n == 0) {
		return;
	}
	n--;
	printRecursion(n);
	printf("I love Recursion\n");
}

int main(int argc, char *argv[])
{
	int count = atoi(argv[1]);
	printRecursion(count);
	return 0;
}
