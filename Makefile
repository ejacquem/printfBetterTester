CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		= main.c tests/print_tests.c tests/test_basic_extended.c tests/test_basic.c tests/test_minus.c tests/test_dot.c \
			tests/test_number.c print_header.c utils.c
OBJS	= $(SRC:.c=.o)

all: $(OBJS) printf
	$(CC) $(CFLAGS) $(OBJS) -L../ -lftprintf -o run_test
	make clean
	./run_test

# run:
# 	make clean && ./run_test

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) output.txt run_test

re: fclean all

short: $(OBJS) printf
	$(CC) $(CFLAGS) $(OBJS) -L../ -lftprintf -o run_test
	make clean
	./run_test 1

printf:
	cd .. && $(MAKE) re

.PHONY: all clean fclean re
