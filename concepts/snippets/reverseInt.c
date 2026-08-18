#include <limits.h>
#include <stdio.h>

int reverse(int x)
{
	long long r = 0;
	while (x) { r = r * 10 + x % 10; x /= 10; }
	return (r < INT_MIN || r > INT_MAX) ? 0 : (int)r;
}

int main(int argc, char *argv[])
{
	int num = 105;
	int res = 0;
	printf("num=%d\n", num);

    res = reverse(num);

	printf("result=%d\n", res);
	return 0;
}
