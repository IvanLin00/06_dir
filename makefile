all: dir.c
	gcc dir.c

run:
	./a.out

clean:
	rm *.o
	rm program
