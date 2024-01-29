CC = gcc
CFLAGS = -Wall -Werror
TARGET = test
SRCS = list.c test.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean run

all: clean $(TARGET) run

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS) *.exe
