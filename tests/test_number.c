#include "../printftest.h"
//
// this will tests if every variable works well 
//

// % cdiuxXps

static void	test_d()
{
		test_number("%0d");
		test_number("%3d");
		test_number("%20d");
}

static void	test_c()
{
		test_char("%0c");
		test_char("%3c");
		test_char("%20c");
}

static void	test_i()
{
		test_number("%0i");
		test_number("%3i");
		test_number("%20i");
}

static void	test_u()
{
		test_number("%0u");
		test_number("%3u");
		test_number("%20u");
}

static void	test_x()
{
		test_number("%0x");
		test_number("%3x");
		test_number("%20x");
}

static void	test_X()
{
		test_number("%0X");
		test_number("%3X");
		test_number("%20X");
}

static void	test_p()
{
		test_pointer("%1p");
		test_pointer("%2p");
		test_pointer("%3p");
		test_pointer("%4p");
		test_pointer("%5p");
		test_pointer("%6p");
		test_pointer("%7p");
		test_pointer("%20p");
}

static void	test_s()
{
		test_string("%0s");
		test_string("%1s");
		test_string("%2s");
		test_string("%3s");
		test_string("%4s");
		test_string("%5s");
		test_string("%6s");
		test_string("%7s");
		test_string("%8s");
		test_string("%20s");
}

void	print_test_number()
{
	printf("#Number Tests\n");
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
