#include "../ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef PRINTFTEST_H
# define PRINTFTEST_H


# define MAX_INT 2147483647
# define MIN_INT -2147483648
#define pointer (void *)(long long)

char *readFileToString(const char *filename);

void print_advanced_test_s();
void print_advanced_test_u();
void print_advanced_test_d();
void print_advanced_test_p();
void print_test_mix();
void print_test_d(char *s, int d);
void print_test_s(char *s, char *input);
void print_test_p(char *s, const void *input);

void	print_test_basic();
void	print_test_basic_extended();
void	print_test_number();
void	print_test_minus();
void	print_test_dot();


void	test_number(char *s);
void	test_pointer(char *s);
void	test_string(char *s);
void	test_char(char *s);


void print_Header1(int terminalWidth);
void print_Header2(int terminalWidth, char *s);
void print_Header3(char *s);
void printn(char c, int n);

#endif