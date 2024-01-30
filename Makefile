MAIN = main
SUB1 = smoothing

CC = gcc
EDITOR = vim
EPARAM = -p
SRCS = ./src
INCS = ./include
BINS = ./bin
BUILD = ./build
LIBS = -lm
CFLAGS = -I$(INCS)
PARAM = -O0

PROGRAM = run
OBJS = $(BINS)/$(MAIN).o $(BINS)/$(SUB1).o
CODES = $(SRCS)/$(MAIN).c $(SRCS)/$(SUB1).c

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $< $(PARAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $^ $(LIBS) $(PARAM)

chmod : $(PROGRAM)
	sudo chmod +x $(BUILD)/$(PROGRAM)

execute: all chmod
	$(BUILD)/$(PROGRAM) $(FILE) $(COUNT)
	cat $(FILE)

all: clean mkdir $(PROGRAM)

clean:
	rm -rf $(BUILD) $(BINS)

mkdir:
	mkdir $(BUILD) $(BINS)

edit:
	$(EDITOR) $(EPARAM) $(INCS)/* $(SRCS)/*

$(BINS)/$(MAIN).o: $(SRCS)/$(MAIN).c $(INCS)/$(MAIN).h
	$(CC) $(CFLAGS) -o $@ -c $< $(PARAM)

$(BINS)/$(SUB1).o: $(SRCS)/$(SUB1).c $(INCS)/$(SUB1).h
	$(CC) $(CFLAGS) -o $@ -c $< $(PARAM)

