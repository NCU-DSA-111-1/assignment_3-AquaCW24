SOURCES := $(wildcard src/*.c)
# LIBRARY := $(wildcard src/*.c)
HUFF := $(wildcard library/huffman/*.c)
ARTH := $(wildcard library/arth/*.c)


all: arth huff main crap
arth: FORCE

FORCE:
	gcc $(ARTH) -o ./obj/arth.o

huff:
	gcc $(HUFF) -o ./obj/huff.o

crap:
	gcc ./library/grepwordgen.c  -g -o ./obj/grepwordgen.o

main:
	gcc $(SOURCES) -g -o ./build/main.o
