ADJ = 1
OUT = ./Smoothed

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
	$(BUILD)/$(PROGRAM) 1 $(OUT)/Smoothed1
	$(BUILD)/$(PROGRAM) 2 $(OUT)/Smoothed2
	$(BUILD)/$(PROGRAM) 3 $(OUT)/Smoothed3
	$(BUILD)/$(PROGRAM) 4 $(OUT)/Smoothed4
	$(BUILD)/$(PROGRAM) 5 $(OUT)/Smoothed5
	$(BUILD)/$(PROGRAM) 6 $(OUT)/Smoothed6
	$(BUILD)/$(PROGRAM) 7 $(OUT)/Smoothed7
	$(BUILD)/$(PROGRAM) 8 $(OUT)/Smoothed8
	$(BUILD)/$(PROGRAM) 9 $(OUT)/Smoothed9

all: clean mkdir $(PROGRAM)

clean:
	rm -rf $(BUILD) $(BINS)

mkdir:
	mkdir $(BUILD) $(BINS)

edit:
	$(EDITOR) $(EPARAM) $(INCS)/* $(SRCS)/* Makefile

$(BINS)/$(MAIN).o: $(SRCS)/$(MAIN).c $(INCS)/$(MAIN).h
	$(CC) $(CFLAGS) -o $@ -c $< $(PARAM)

$(BINS)/$(SUB1).o: $(SRCS)/$(SUB1).c $(INCS)/$(SUB1).h
	$(CC) $(CFLAGS) -o $@ -c $< $(PARAM)

