CC = gcc
CFLAGS = -Wall
TARGET = test
SRCS = list.c test.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

# Default target
all: $(TARGET)

# Rule to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to create object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean the build products
clean:
	rm -f $(TARGET) $(OBJS) *.exe
