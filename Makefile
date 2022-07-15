CC = gcc 
TARGET = jebanjemozka.c -o jebanjemozka
ERRORS = -Wall -Wextra -pedantic-errors

.PHONY: clean

lsc: jebanjemozka.c
		${CC} ${TARGET} -O3

debug: jebanjemozka.c
		${CC} ${TARGET} ${ERRORS} -Og

clean:
		rm -f jebanjemozka	