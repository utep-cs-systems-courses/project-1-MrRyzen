# compiler flags. -g for debug, -03 for optimization
CFLAGS=-g -O3

all: mainUI

tokenizer.o: tokenizer.h tokenizer.c

mainUI.o: tokenizer.h mainUI.c

mainUI: mainUI.o tokenizer.o
	   cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o mainUI
