#include "../ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef PRINTFTEST_H
# define PRINTFTEST_H

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
void	print_test_minus();
void	print_test_dot();


void	test_number(char *s);
void	test_pointer(char *s);
void	test_string(char *s);
void	test_char(char *s);

#endif