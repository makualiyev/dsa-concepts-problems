solution: solution.c
	$(CC) solution.c -o solution -Wall -Wextra -Wno-unused-variable -Wconversion -Wshadow -Wcast-qual -fstack-protector-strong -pedantic -std=c99 -g -lm -fsanitize=address,undefined
solution1: solution.c
	$(CC) solution.c -o solution -Wall -pedantic -std=c99 -g -lm
test: solution1.c
	$(CC) solution1.c -o solution1 -Wall -Wextra -Wno-unused-variable -Wconversion -Wshadow -Wcast-qual -fstack-protector-strong -pedantic -std=c99 -g -lm -fsanitize=address,undefined