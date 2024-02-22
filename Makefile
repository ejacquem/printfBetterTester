CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		= main.c tests/print_tests.c tests/test_basic.c tests/test_minus.c tests/test_dot.c 
OBJS	= $(SRC:.c=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L../ -lftprintf -o run_test

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) a.out

re: fclean all

.PHONY: all clean fclean re
