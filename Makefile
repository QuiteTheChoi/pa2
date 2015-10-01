all: sorted-list.h sorted-list.c main.c
	gcc -g -o sl sorted-list.c main.c

run:
	./sl

debug:
	gdb ./sl

clean:
	rm -rf *.o sl
	rm -rf *.dSYM sl
