OBJ	= main.o operationParserCat.o cat.o errorProcessingCat.o
OUT	= s21_cat
TESTFILE = tests/tests_script_cat.sh

CC		= gcc
FLAGS	= -c -Wall -Werror -Wextra
LFLAGS	= -std=c11 -Wall -Werror -Wextra

all: s21_cat

s21_cat: $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) -o $(OUT)
	rm -f $(OBJ)

tests: rebuild
	sh $(TESTFILE)
	rm -f $(OUT)

main.o: main.c
	$(CC) $(FLAGS) main.c

operationParserCat.o: operationParserCat.c
	$(CC) $(FLAGS) operationParserCat.c

errorProcessingCat.o: errorProcessingCat.c
	$(CC) $(FLAGS) errorProcessingCat.c

cat.o: cat.c
	$(CC) $(FLAGS) cat.c

rebuild: clean all

clean:
	rm -f $(OBJ) $(OUT)