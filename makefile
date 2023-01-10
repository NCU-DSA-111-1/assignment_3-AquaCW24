SOURCES := $(wildcard src/*.c)
# LIBRARY := $(wildcard src/*.c)
HUFF := $(wildcard lib/chuffman/*.c)
ARTH := $(wildcard lib/arth/*.c)


all: arth huff main crap
arth: FORCE

FORCE:
	gcc $(ARTH) -o ./obj/arth.o

huff:
	gcc $(HUFF) -o ./obj/huff.o

crap:
	gcc ./lib/grepwordgen.c  -g -o ./obj/grepwordgen.o

main:
	gcc $(SOURCES) -g -o ./obj/main.o
