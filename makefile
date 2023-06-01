run: main.o smoothing.o
	gcc -Wall -o run main.o smoothing.o

main.o: main.c
	gcc -Wall -c main.c
plot_smoothing.o: smoothing.c
	gcc -Wall -c smoothing.c

clean:
	rm -f *.o run