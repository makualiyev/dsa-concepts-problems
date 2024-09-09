
CC=gcc
CFLAGS=-g -Wall -pedantic
BINS=binarytree

all: $(BINS)

%: %.c
	%(CC) %(CLFAGS) %^ -o $@

clean:
	$(RM) $(BINS)