CC = gcc 
TARGET = jebanjemozga.c -o jebanjemozga
ERRORS = -Wall -Wextra -pedantic-errors

.PHONY: clean

jebanjemozga: jebanjemozga.c
		${CC} ${TARGET} -O3

debug: jebanjemozga.c
		${CC} ${TARGET} ${ERRORS} -Og

clean:
		rm -f jebanjemozga	
