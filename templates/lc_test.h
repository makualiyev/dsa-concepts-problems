#ifndef LC_TEST_H
#define LC_TEST_H
#include <stdio.h>

static int lc_failures;

#define CHECK(cond) do { if (!(cond)) { \
	printf(" FAIL %s:%d	%s\n", __FILE__, __LINE__, #cond); lc_failures++; } } while (0)

#define CHECK_INT(got, want) do { long _g = (got), _w = (want); \
	if (_g != _w) { printf(" FAIL %s:%d %s == %s (got %ld, want %ld)\n", \
	__FILE__, __LINE__, #got, #want, _g, _w); lc_failures++; } } while (0)

static inline int lc_summary(void) {
	if (lc_failures) printf("%d check(s) FAILED\n", lc_failures);
	else			 printf("all checks passed\n");
	return lc_failures != 0;
}
#endif
