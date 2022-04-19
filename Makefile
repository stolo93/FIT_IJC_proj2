CC=gcc
CFLAGS= -g -Wall  -Wextra -std=c11 -fPIC -O2
OBJS= htab_init.o htab_size.o htab_bucket_count.o htab_find.o htab_resize.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o htab_hash_function.o
LOGIN = xstola03

all: tail wordcount wordcount-dynamic

tail:tail.o
	$(CC) $(CFLAGS) $^ -o $@

wordcount: libhtab.a wordcount.o io.o
	gcc -o $@ -static wordcount.o io.o -L. -lhtab

wordcount-dynamic: libhtab.so wordcount.o io.o
	gcc -o $@ wordcount.o io.o -L. -lhtab

libhtab.a: $(OBJS)
	ar rsc $@ $^

libhtab.so: $(OBJS)
	gcc -shared -fPIC -o $@ $^ 

-include deps #generated by gcc -MM *.c

.PHONY: zip clean

zip: *.c *.cc *.h Makefile
	zip $(LOGIN).$@ $^

clean:
	rm *.o tail libhtab.* wordcount wordcount-dynamic