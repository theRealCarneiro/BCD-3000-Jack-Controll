PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

CC = gcc
CCFLAGS= -lasound

TARGET = BCD
SRC = BCD_3000_Midi.c
OBJ = ${SRC:.c=.o}

BCD:	${OBJ}
	${CC} ${OBJ} -o $@ ${CCFLAGS}

.c.o:
	${CC} -c ${SRC}

${OBJ}:	config.h

clean:
	rm -rf *.o ${TARGET}

install:	BCD
	install BCD ${PREFIX}/bin

uninstall:
	rm ${PREFIX}/bin/BCD

.PHONY: clean install uninstall
