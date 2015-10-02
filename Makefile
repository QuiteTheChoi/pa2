all: main

libsl.a: sorted-list.o
	ar rv libsl.a sorted-list.o

sorted-list.o: sorted-list.c sorted-list.h
	gcc -c sorted-list.c

main: main.c libsl.a
	gcc -o sl main.c libsl.a

run:
	./sl

debug: sorted-list.h sorted-list.c main.c
	gcc -g -o test sorted-list.c main.c
	gdb ./test

clean:
	rm -rf *.o sl
