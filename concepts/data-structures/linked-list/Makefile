CC=gcc
CFLAGS=-Wall -Wextra -Wno-unused-variable -Wconversion -Wshadow -Wcast-qual -fstack-protector-strong -pedantic -std=c99 -g -lm -fsanitize=address,undefined
RM=rm -f

linked-list-recur: linked-list-recur.c
	$(CC) $(CFLAGS) linked-list-recur.c -o linked-list-recur
reverseLinkedList: reverseLinkedList.c
	$(CC) $(CFLAGS) reverseLinkedList.c -o reverseLinkedList 