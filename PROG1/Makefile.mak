# Makefile
#--------------------------------------------------------------
# Program #1
#--------------------------------------------------------------
CC=gcc
CFLAGS_DBG=-g -ggdb -gdwarf-4 -O0 -Wall -Wextra
CFLAGS=-Wall -Wextra

ALL := list

all: ${ALL}

list: list_library.o list.c
	${CC} ${CFLAGS} list.c list_library.o -o list 

list_library.o: list_library.c list_library.h
	${CC} ${CFLAGS} -c list_library.c -o list_library.o

clean:
	rm -vf ${ALL} core* *.o *~
	rm -fr *dSYM
