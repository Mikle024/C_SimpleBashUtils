OBJ	= main.o operationParserGrep.o grep.o errorProcessingGrep.o
OUT	= s21_grep
TESTFILE = tests/tests_script_grep.sh

CC		= gcc
FLAGS	= -c -Wall -Werror -Wextra
LFLAGS	= -std=c11 -Wall -Werror -Wextra

all: s21_grep

s21_grep: $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) -o $(OUT)
	rm -f $(OBJ)

tests: rebuild
	sh $(TESTFILE)
	rm -f $(OUT)

main.o: main.c
	$(CC) $(FLAGS) main.c

operationParserGrep.o: operationParserGrep.c
	$(CC) $(FLAGS) operationParserGrep.c

grep.o: grep.c
	$(CC) $(FLAGS) grep.c

errorProcessingGrep.o: errorProcessingGrep.c
	$(CC) $(FLAGS) errorProcessingGrep.c

rebuild: clean all

clean:
	rm -f $(OBJ) $(OUT)