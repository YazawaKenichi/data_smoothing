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

PROGRAM = Smoother
OBJS = $(BINS)/$(MAIN).o $(BINS)/$(SUB1).o
CODES = $(SRCS)/$(MAIN).c $(SRCS)/$(SUB1).c

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $^ $(LIBS)

chmld: $(PROGRAM)
	sudo chmod +x $(BUILD)/$(PROGRAM)

execute: $(PROGRAM)
	$(BUILD)/$(PROGRAM)

all: clean $(PROGRAM)

clean:
	rm -rf $(BUILD) $(BINS)
	mkdir $(BUILD) $(BINS)

edit: editting $(PROGRAM)

editting:
	$(EDITOR) $(EPARAM) $(INCS)/* $(SRCS)/*

# 以下を変更
# ゆーて使わないようにできてる
$(BINS)/$(MAIN).o: $(SRCS)/$(MAIN).c $(INCS)/$(MAIN).h
	$(CC) $(CFLAGS) -o $@ -c $<
$(BINS)/$(SUB1).o: $(SRCS)/$(SUB1).c $(INCS)/$(SUB1).h
	$(CC) $(CFLAGS) -o $@ -c $<


