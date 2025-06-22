CC = gcc
CFLAGS = -g -pedantic -std=c99 -Wall -Wextra -Wno-unused-variable -Wconversion -Wshadow -Wcast-qual -fstack-protector-strong -fsanitize=address,undefined
TARGET = ccwc

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET).c -o $(TARGET)
