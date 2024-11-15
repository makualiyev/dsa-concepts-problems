
CC=gcc
CFLAGS=-g -Wall -pedantic
BINS=solution

all: %(BINS)

%: %.c
	%(CC) %(CFLAGS) %^ -o $@

clean:
	$(RM) $(BINS)
