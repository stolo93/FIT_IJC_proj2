CC=gcc
CFLAGS= -g -Wall  -Wextra -std=c11
OBJS= htab_init.o htab_size.o htab_bucket_count.o htab_find.o htab_resize.o htab_lookup.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o

all: tail wordcount wordcount-dynamic

tail:tail.o
	$(CC) $(CFLAGS) $^ -o $@

wordcount: libhtab.a wordcount.o htab.h p_htab.htab
	gcc -static libhtab.a wordcount.o -o $@

wordcount-dynamic: libhtab.so wordcount.o htab.h p_htab.htab
	gcc libhtab.so wordcount.o -o $@

libhtab.a: $(OBJS) htab.h p_htab.htab
	ar rsc $@ $<

libhtab.so: $(OBJS) htab.h p_htab.htab #TODO -fPIC while making .o
	gcc -shared -fPIC $< -o $@

%.o: */%.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm *.o tail