CC=gcc
CFLAGS=-g -Wall -pedantic -std=c99 -fsanitize=address
RM=rm -f

TARGET=recur_1

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
