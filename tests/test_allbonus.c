#include "../printftest.h"

static void	test_d()
{
	test_number("% 0d");
	test_number("% 3d");
	test_number("% 20d");
	test_number("%+0d");
	test_number("%+3d");
	test_number("%+20d");
}

static void	test_c()
{
	test_char("%#0c");
	test_char("%#3c");
	test_char("%#20c");
}

static void	test_i()
{
	test_number("% 0i");
	test_number("% 3i");
	test_number("% 20i");
	test_number("%+0i");
	test_number("%+3i");
	test_number("%+20i");
}

static void	test_x()
{
	test_number("%#0x");
	test_number("%#3x");
	test_number("%#20x");
}

static void	test_X()
{
	test_number("%#0X");
	test_number("%#3X");
	test_number("%#20X");
}

void	print_test_bonus()
{
	printf("#Bonus Tests\n");
	printf("#TEST Decimal (%%d) \n");
	test_d();
	printf("#TEST Integer (%%i) \n");
	test_i();
	printf("#TEST Character (%%c) \n");
	test_c();
	printf("#TEST Hexadecimal (%%x) \n");
	test_x();
	printf("#TEST HEXADECIMAL (%%X) \n");
	test_X();
	printf("#TEST special (%%s) \n");

	print_test_d("%+1.0i", 0);
	print_test_d("%+8.0d", 0);
	print_test_d("%+5.0i", 0);
	print_test_d("%-+6.0i", 0);
	print_test_d("%+-7.0i", 0);
	print_test_d("%+-0.0i", 0);
	print_test_d("%+-8.0i", -1);
	print_test_d("% 5.0i", 0);
	print_test_d("%5.0i", 0);
	print_test_d("%5.1i", 0);
}
