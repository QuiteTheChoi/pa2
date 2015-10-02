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

git1:
	git add .
	git commit -m "Added Stuff - JCaverly"
	git push

git2:
	git add .
	git commit -m "Added stuff - JGetahun"
	git push

vim1:
	vim sorted-list.c

vim2:
	vim main.c

vim3:
	vim sorted-list.h
	
vim4:
	vim makefile

clean:
	rm -rf *.o sl
	rm -rf *.a
