#include "../printftest.h"
//
// this will tests if every variable works well 
//

// % cdiuxXps

static void	test_d()
{
		test_number("%0d");
		test_number("%03d");
		test_number("%020d");
}

static void	test_c()
{
		test_char("%0c");
		test_char("%03c");
		test_char("%020c");
}

static void	test_i()
{
		test_number("%00i");
		test_number("%03i");
		test_number("%020i");
}

static void	test_u()
{
		test_number("%00u");
		test_number("%03u");
		test_number("%020u");
}

static void	test_x()
{
		test_number("%00x");
		test_number("%03x");
		test_number("%020x");
}

static void	test_X()
{
		test_number("%00X");
		test_number("%03X");
		test_number("%020X");
}

static void	test_s()
{
		test_string("%00s");
		test_string("%03s");
		test_string("%04s");
		test_string("%05s");
		test_string("%06s");
		test_string("%07s");
		test_string("%020s");
}

void	print_test_zero()
{
	printf("#Zero Tests\n");
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
	printf("#TEST String (%%s) \n");
	test_s();
}
