CC=gcc
CFLAGS= -g -Wall -Werror -Wextra -std=c11

all: tail

tail:tail.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm *.o tail