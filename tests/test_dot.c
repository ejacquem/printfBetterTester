#include "../printftest.h"
//
// this will tests if every variable works well 
//

// % cdiuxXps

static void	test_d()
{
	print_test_d("%.0d", 42);
	test_number("%.d");
	test_number("%.3d");
	test_number("%.20d");
	test_number("%5.d");
	test_number("%5.3d");
	test_number("%5.20d");
}

static void	test_c()
{
	test_char("%.c");
	test_char("%.3c");
	test_char("%.20c");
	test_char("%5.c");
	test_char("%5.3c");
	test_char("%5.20c");
}

static void	test_i()
{
	print_test_d("%.0i", 42);
	test_number("%.i");
	test_number("%.3i");
	test_number("%.20i");
	test_number("%5.i");
	test_number("%5.3i");
	test_number("%5.20i");
}

static void	test_u()
{
	test_number("%.u");
	test_number("%.3u");
	test_number("%.20u");
	test_number("%5.u");
	test_number("%5.3u");
	test_number("%5.20u");
}

static void	test_x()
{
	test_number("%.x");
	test_number("%.3x");
	test_number("%.20x");
	test_number("%5.x");
	test_number("%5.3x");
	test_number("%5.20x");
}

static void	test_X()
{
	test_number("%.X");
	test_number("%.3X");
	test_number("%.20X");
	test_number("%5.X");
	test_number("%5.3X");
	test_number("%5.20X");
}

static void	test_p()
{
		test_pointer("%.p");
		test_pointer("%.3p");
		test_pointer("%.20p");
		test_pointer("%5.p");
		test_pointer("%5.3p");
		test_pointer("%5.20p");
}

static void	test_s()
{
		test_string("%.s");
		test_string("%.3s");
		test_string("%.20s");
		test_string("%5.s");
		test_string("%5.3s");
		test_string("%5.20s");
}

void	print_test_dot()
{
	printf("#Dot Tests\n");
	printf("#TEST Decimal (%%d) \n");
	test_d();
	printf("#TEST Integer (%%i) \n");
	test_i();
	printf("#TEST Character (%%c) \n");
	test_c();
	printf("#TEST Unsigned Int (%%u) \n");
	test_u();
	printf("#TEST Hexadecimal (%%x) \n");
	test_x();
	printf("#TEST HEXADECIMAL (%%X) \n");
	test_X();
	printf("#TEST Pointer (%%p) \n");
	test_p();
	printf("#TEST String (%%s) \n");
	test_s();
}