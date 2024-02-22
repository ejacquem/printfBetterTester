#include "../printftest.h"
//
// this will tests if every variable works well 
//

// % cdiuxXps

void	test_d()
{
	test_number("%d");
	test_number(" %d ");
}

void	test_c()
{
	test_char("%c");
	test_char(" %c ");
}

void	test_i()
{
	test_number("%i");
	test_number(" %i ");
}

void	test_u()
{
	test_number("%u");
	test_number(" %u ");
}

void	test_x()
{
	test_number("%x");
	test_number(" %x ");
}

void	test_X()
{
	test_number("%X");
	test_number(" %X ");
}

void	test_p()
{
	test_pointer("%p");
	test_pointer(" %p ");
}

void	test_s()
{
	test_string("%s");
	test_string(" %s ");
}

void	print_test_basic_extended()
{
	printf("#Basic Tests Extended\n");
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