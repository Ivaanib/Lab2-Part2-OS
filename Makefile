

# Makefile for compiling signal.c and timer.c

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Target executables
TARGETS = signalab timerab

# Source files
SRC = signal.c timer.c

# Build rule
all: $(TARGETS)

signalab: signal.c
	$(CC) $(CFLAGS) signal.c -o signalab

timerab: timer.c
	$(CC) $(CFLAGS) timer.c -o timerab

# Clean rule
clean:
	rm -f $(TARGETS)

