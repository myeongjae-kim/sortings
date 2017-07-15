# Compiler and Compile options.
C = gcc
CFLAGS = -g -Wall -Wextra -Wpedantic -std=c11

# Macros specifying path for compile.
SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)
BIN = ./bin/
INC = ./include/
LIB = ./lib/

# Pre-Processor.
CFLAGS += -I$(INC)

# Compile command.
TARGET = a.out
$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) $(CPPFLAGS) -o $(BIN)$(TARGET) $(OBJS) -L$(LIB)
	$(BIN)$(TARGET)

# Delete binary & object files.
clean:
	rm $(BIN)$(TARGET) $(OBJS)
