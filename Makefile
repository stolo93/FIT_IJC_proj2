CC=gcc
CFLAGS= -g -Wall  -Wextra -std=c11
OBJS= htab_init.o htab_size.o htab_bucket_count.o htab_find.o htab_resize.o htab_lookup.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o

all: tail libhtab.a

tail:tail.o
	$(CC) $(CFLAGS) $^ -o $@

libhtab.a: $(OBJS) htab.h p_htab.htab
	ar rsc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm *.o tail