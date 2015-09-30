all: sorted-list.h sorted-list.c main.c
	gcc -g -o sorted-list sorted-list.c main.c

run:
	./sorted-list

debug:
	gdb ./sorted-list

clean:
	rm -rf *.o sorted-list
	rm -rf *.dSYM sorted-list
