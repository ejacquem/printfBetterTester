#include "../printftest.h"

void	test_number(char *s)
{
	print_test_d(s, 42);
	print_test_d(s, 0);
	print_test_d(s, 1);
	print_test_d(s, -1);
	print_test_d(s, 15);
	print_test_d(s, 16);
	print_test_d(s, MAX_INT);
	print_test_d(s, MIN_INT);
	print_test_d(s, 1000000000);
	print_test_d(s, -1000000000);
}

void	test_pointer(char *s)
{
	char a, b;
	a = b = 0;
	print_test_p(s, &a);
	print_test_p(s, &b);
	print_test_p(s, pointer MIN_INT);
	print_test_p(s, pointer MAX_INT);
	print_test_p(s, pointer MAX_ULLONG);
	print_test_p(s, pointer 0);
}

void	test_string(char *s)
{
	print_test_s(s, "Hello World !");
	print_test_s(s, "42");
	print_test_s(s, "");
	print_test_s(s, 0);
}

void	test_char(char *s)
{
	// char null is crashing :(
	// print_test_d(s, 0);
	print_test_d(s, ' ');
	print_test_d(s, 'a');
	print_test_d(s, 'z');
	print_test_d(s, 'A');
	print_test_d(s, 1);
	print_test_d(s, 127);
}