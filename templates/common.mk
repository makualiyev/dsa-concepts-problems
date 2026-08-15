CC	?= gcc
ROOT	:= $(dir $(lastword $(MAKEFILE_LIST)))
CFLAGS	:= -std=c99 -g -O0 -I$(ROOT) -I$(ROOT)include \
		   -Wall -Wextra -Wconversion -Wshadow -Wcast-qual -pedantic \
		   -Wno-unused-variable -fstack-protector-strong
LDLIBS	:= -lm
SAN		:= -fsanitize=address,undefined

.PHONY:	test bench paste clean
test: ; @$(CC) $(CFLAGS) $(SAN) tests.c -o tests $(LDLIBS) && ./tests
bench: ; @$(CC) $(CFLAGS) -O2 -DBENCH tests.c -o bench $(LDLIBS) && ./bench
paste: ; @sed '/#include "/d' solution.c | (pbcopy || xclip -sel clip || cat) 2>/dev/null
clean: ; $(RM) tests bench
