##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Compiles better each time it goes down
##

CC	=	gcc

CFLAGS	=	-Wextra -Wall -Werror -I./include/

DFLAGS	=	-ggdb -g3

TFLAGS	=	$(CFLAGS) --coverage -lcriterion

NFLAGS = -lncurses

NAME	=	42sh

MAIN	=	./main.c

SRC	=	$(shell find -depth -name "*.c" -path "./src/*")

TESTSRC	=	$(shell find -depth -name "*.c" -path "./*" | grep -v $(MAIN))

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS) $(NFLAGS)

debug:
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(LIB) $(CFLAGS) $(DFLAGS) $(NFLAGS)

all: $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *~

fclean: clean
	rm -rf $(NAME)
	rm -rf unit_tests

re: fclean all

unit_tests: fclean
	gcc $(TESTSRC) -o unit_tests $(TFLAGS)

tests_run: unit_tests
	./unit_tests

test_result: tests_run
	gcovr --exclude tests
	gcovr --exclude tests --branches

cs: fclean
	coding-style . >> /dev/null
	cat coding-style-reports.log
	rm -rf coding-style-reports.log

valproof:
	valgrind ./test_42sh.sh 2>&1 | grep "ERROR"
	valgrind ./test_42sh.sh 2>&1 | grep "lost"
