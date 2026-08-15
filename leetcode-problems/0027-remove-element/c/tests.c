#include "lc.h"
#include "lc_test.h"
#include "solution.c"

#ifdef BENCH
#include <time.h>

int main(void) {
	enum { N = 100000, REPS = 2000 };
	static int base[N], scratch[N];
	for (int i = 0; i < N; i++) base[i] = i % 3;

	volatile int sink = 0;
	clock_t t0 = clock();
	for (int r = 0; r < REPS; r++) {
		for (int i = 0; i < N; i++) scratch[i] = base[i];
		sink += removeElement(scratch, N, 2);
	}
	clock_t t1 = clock();
	(void)sink;

	printf("removeElement: %d reps, N=%d, %.3f s total (%.1f ns/call)\n",
			REPS, N, (double)(t1 - t0) / CLOCKS_PER_SEC,
			(double)(t1 - t0) / CLOCKS_PER_SEC / REPS * 1e9);
	return 0;
}

#else

static void run(int *nums, int n, int val, int wantK) {
	int k = removeElement(nums, n, val);
	CHECK_INT(k, wantK);
	for (int i = 0; i < k; i++) CHECK(nums[i] != val);
}

int main(void) {
	{ int a[] = {3,2,2,3};		run(a, 4, 3, 2); }
	{ int a[] = {0,1,2,2,3,0,4,2};		run(a, 8, 2, 5); }
	{ int a[] = {2};		run(a, 1, 3, 1); }
	return lc_summary();
}
#endif
