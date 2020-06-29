# compiler flags. -g for debug, -03 for optimization
CFLAGS=-g -O3

all: mainUI

history.o: history.h history.c tokenizer.h

tokenizer.o: tokenizer.h tokenizer.c

mainUI.o: history.h tokenizer.h mainUI.c

mainUI: mainUI.o tokenizer.o history.o
	   cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o mainUI
