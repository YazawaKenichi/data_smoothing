run: main.o smoothing_64.o
	gcc -Wall -o run main.o smoothing_64.o

main.o: main.c
	gcc -Wall -c main.c
smoothing_64.o: smoothing_64.c
	gcc -Wall -c smoothing_64.c

clean:
	rm -f *.o run