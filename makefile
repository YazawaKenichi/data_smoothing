run: main.o plot_smoothing.o
	gcc -Wall -o do main.o plot_smoothing.o

main.o: main.c
	gcc -Wall -c main.c
plot_smoothing.o: plot_smoothing.c
	gcc -Wall -c plot_smoothing.c

clean: rm -f *.o run