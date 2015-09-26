all: sorted-list.h sorted-list.c main.c
	gcc -g -o sorted-list sorted-list.c main.c

clean:
	rm -rf *.o sorted-list
	rm -rf *.dSYM sorted-list
