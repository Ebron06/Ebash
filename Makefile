#Example make SRC=main.c
SRC ?= main.c

TARGET := $(basename $(SRC))

#Compiler to use 
CC = gcc

CFLAGS = -Wall -g -lreadline

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $< -o $@ 

clean:
	rm -f $(TARGET:ARGET)
