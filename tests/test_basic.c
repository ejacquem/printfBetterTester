#include "../printftest.h"

void	print_test_basic()
{
	printf("#Basic Tests\n");

	print_test_d("%d", 42);
	print_test_d("%d", 0);
	print_test_d("%d", MAX_INT);
	print_test_d("%d", MIN_INT);
	print_test_d("%d", -1);
	print_test_d("%d", 1000);
	print_test_d("%d", -1000);

	print_test_d("n = %d", 1);
	print_test_d("%d is great", 42);
	print_test_d("before %d after", 0);

	print_test_d("%i", 0);
	print_test_d("%i", MAX_INT);
	print_test_d("%i", MIN_INT);

	print_test_d("%c", 'a');
	print_test_d("%c", ' ');
	print_test_d("%c", 127);
	print_test_d("a %c c", 'b');

	print_test_d("%u", -42);
	print_test_d("%u", 0);
	print_test_d("%u", MAX_INT);
	print_test_d("%u", MIN_INT);
	print_test_d("%u", MAX_UINT);
	print_test_d("%u", (MAX_UINT * -1));
	print_test_d("%u", 2147483648U);
	print_test_d("%u", -1);

	print_test_d("%x", 0);
	print_test_d("%x", 1);
	print_test_d("%x", 9);
	print_test_d("%x", 10);
	print_test_d("%x", 15);
	print_test_d("%x", 16);
	print_test_d("%x", MAX_INT);
	print_test_d("%x", MIN_INT);

	print_test_d("%X", 10);
	print_test_d("%X", 15);
	print_test_d("%X", 16);
	print_test_d("%X", MAX_INT);
	print_test_d("%X", MIN_INT);

	print_test_s("%s", "Hello world !");
	print_test_s("%s", "a");
	print_test_s("%s", "");
	print_test_s("%s", 0);
	print_test_s("Hello%s !", " world");

	int i = 0, a = 0, b = 0;

	print_test_p("%p", &i);
	print_test_p("%p", &a);
	print_test_p("%p", &b);
	print_test_p("%p", 0);
	print_test_p("%p", pointer 0xFFFFFFFFFFFFFFFFUL);
	print_test_p("%p", pointer 0x7FFFFFFFFFFFFFFFUL);
	print_test_p("%p", pointer 0xFFFFFFFF80000000UL);

//tests if the input is correctly cast
	print_test_l("%d", MAX_LONG);
	print_test_l("%d", MIN_LONG);
	print_test_l("%d", MAX_ULLONG);
	print_test_l("%d", MAX_UINT);

	print_test_l("%i", MAX_LONG);
	print_test_l("%i", MIN_LONG);
	print_test_l("%i", MAX_ULLONG);
	print_test_l("%i", MAX_UINT);

	print_test_l("%u", MAX_LONG);
	print_test_l("%u", MIN_LONG);
	print_test_l("%u", MAX_ULLONG);
	print_test_l("%u", MAX_UINT);

	print_test_l("%x", MAX_LONG);
	print_test_l("%x", MIN_LONG);
	print_test_l("%x", MAX_ULLONG);
	print_test_l("%x", MAX_UINT);

	print_test_l("%X", MAX_LONG);
	print_test_l("%X", MIN_LONG);
	print_test_l("%X", MAX_ULLONG);
	print_test_l("%X", MAX_UINT);

	print_test_d("%%%%%d", 42);
	print_test_d("%%%d", 42);
	print_test_d("%%", 42);
}
