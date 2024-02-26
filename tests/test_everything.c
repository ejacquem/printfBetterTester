#include "../printftest.h"

//This will do 100 tests with value from 0-9 on n1 and n2
static void test_loop(char *s, void (* f)(char *s))
{
	int i = 0, j = 0;
	if(f == test_number)
		i = 1;
	while(i <= 9){
		s[2] = i + '0';
		j = 0;
		while(j <= 9){
			s[4] = j + '0';
			f(s);
			j++;
		}
		i++;
	}
}

static void	test_all_s()
{
	char	str[8] = " %*.*s";

	test_loop(str, test_string);
	str[0] = '%';
	str[1] = '-';	
	test_loop(str, test_string);
}

static void	test_all_n(char *s)
{
	char	str[8];
	memcpy(str, s, 8);

	test_loop(str, test_number);
	str[0] = '%';
	str[1] = '-';	
	test_loop(str, test_number);
	str[1] = ' ';	
	test_loop(str, test_number);
	str[1] = '+';	
	test_loop(str, test_number);
}

static void	test_all_x(char *s)
{
	char	str[8];
	memcpy(str, s, 8);

	test_loop(str, test_number);
	str[0] = '%';
	str[1] = '-';
	test_loop(str, test_number);
	str[1] = '#';
	test_loop(str, test_number);
}

static void	test_all_u(char *s)
{
	char	str[8];
	memcpy(str, s, 8);

	test_loop(str, test_number);
	str[0] = '%';
	str[1] = '-';
	test_loop(str, test_number);
}

void	print_test_everything()
{
	printf("#Testing Every Value\n");
	printf("#TEST String (%%s) \n");
	test_all_s();
	printf("#TEST Number (%%d) \n");
	test_all_n(" %*.*d");
	printf("#TEST Number (%%i) \n");
	test_all_n(" %*.*i");
	printf("#TEST Unsigned (%%u) \n");
	test_all_u(" %*.*u");
	printf("#TEST Hexadecimal (%%x) \n");
	test_all_x(" %*.*x");
	printf("#TEST HEXADECIMAL (%%X) \n");
	test_all_x(" %*.*X");
}
