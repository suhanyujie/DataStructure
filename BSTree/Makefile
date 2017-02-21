# this is make file
main: main.o BSTree.o
	gcc -o main main.o BSTree.o
main.o: main.c BSTree.h
	gcc -c main.c
BSTree.o: BSTree.c BSTree.h
	gcc -c BSTree.c
clean:
	rm -rf *.o main 
test:
	echo 123;
