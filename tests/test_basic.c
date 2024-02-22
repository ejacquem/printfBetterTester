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

void	print_test_basic()
{
	printf("#Basic Tests \n");
	printf("#test %%d \n");
	test_d();
	printf("#test %%c \n");
	test_c();
	printf("#test %%i \n");
	test_i();
	printf("#test %%u \n");
	test_u();
	printf("#test %%x \n");
	test_x();
	printf("#test %%X \n");
	test_X();
	printf("#test %%p \n");
	test_p();
	printf("#test %%s \n");
	test_s();
}