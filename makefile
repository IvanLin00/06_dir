all: dir.c
	gcc stat.c

run:
	./a.out

clean:
	rm *.o
	rm program
