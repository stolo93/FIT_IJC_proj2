CC=gcc
CFLAGS= -g -Wall  -Wextra -std=c11
OBJS= htab_init.o htab_size.o htab_bucket_count.o htab_find.o htab_resize.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o
HEADERS = */htab.h */p_htab.h


all: tail wordcount wordcount-dynamic

tail:tail.o
	$(CC) $(CFLAGS) $^ -o $@

wordcount: libhtab.a wordcount.o
	gcc -static libhtab.a wordcount.o -o $@

wordcount-dynamic: libhtab.so wordcount.o 
	gcc libhtab.so wordcount.o -o $@

libhtab.a: $(OBJS) 
	ar rsc $@ $<

libhtab.so: $(OBJS)  #TODO -fPIC while making .o
	gcc -shared -fPIC $< -o $@

%.o: */%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o tail libhtab.* wordcount wordcount-dynamic