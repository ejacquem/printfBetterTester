#include "../printftest.h"
//
// this will tests if every variable works well 
//

// % cdiuxXps

static void	test_d()
{
		test_number("%-d");
		test_number("%-3d");
		test_number("%-20d");
		test_number(" %-d ");
		test_number(" %-3d ");
		test_number(" %-20d ");
}

static void	test_c()
{
		test_char("%-c");
		test_char("%-3c");
		test_char("%-20c");
		test_char(" %-c ");
		test_char(" %-3c ");
		test_char(" %-20c ");
}

static void	test_i()
{
		test_number("%-i");
		test_number("%-3i");
		test_number("%-20i");
		test_number(" %-i ");
		test_number(" %-3i ");
		test_number(" %-20i ");
}

static void	test_u()
{
		test_number("%-u");
		test_number("%-3u");
		test_number("%-20u");
		test_number(" %-u ");
		test_number(" %-3u ");
		test_number(" %-20u ");
}

static void	test_x()
{
		test_number("%-x");
		test_number("%-3x");
		test_number("%-20x");
		test_number(" %-x ");
		test_number(" %-3x ");
		test_number(" %-20x ");
}

static void	test_X()
{
		test_number("%-X");
		test_number("%-3X");
		test_number("%-20X");
		test_number(" %-X ");
		test_number(" %-3X ");
		test_number(" %-20X ");
}

static void	test_p()
{
		test_pointer("%-p");
		test_pointer("%-3p");
		test_pointer("%-20p");
		test_pointer(" %-p ");
		test_pointer(" %-3p ");
		test_pointer(" %-20p ");
}

static void	test_s()
{
		test_string("%-s");
		test_string("%-3s");
		test_string("%-20s");
		test_string(" %-s ");
		test_string(" %-3s ");
		test_string(" %-20s ");
}

void	print_test_minus()
{
	printf("#Minus Tests\n");
	printf("#TEST DECIMAL (%%d) \n");
	test_c();
	printf("#TEST INTEGER (%%i) \n");
	test_d();
	printf("#TEST CHARACTER (%%c) \n");
	test_i();
	printf("#TEST UNSIGNED INT (%%u) \n");
	test_u();
	printf("#TEST HEXADECIMAL (%%x) \n");
	test_x();
	printf("#TEST HEXADECIMAL (uppercase) (%%X) \n");
	test_X();
	printf("#TEST POINTER (%%p) \n");
	test_p();
	printf("#TEST STRING (%%s) \n");
	test_s();
}