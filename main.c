#include "printftest.h"
#include <signal.h>
#include <stdlib.h>

#define MAX_ERROR_NB 20

void bettercompare(char *s);

const char* filename = "output.txt";
int testnb = 0;
int printf_result = 0;
int ft_printf_result = 0;
int short_output = FALSE;


void print_test_l(char *s, long input);

void segfault_handler(int signum) {

	printf("\n#END OF TESTS\n#END OF TESTS\n#END OF TESTS\n");
	printf("\n\nThe test case above made your ft_printf crash.\n\n");
	fflush(stdout);
	
	char *s = readFileToString(filename);

	freopen("/dev/tty", "w", stdout);

	bettercompare(s);

    printf("\n\033[1;38;5;226mERROR : Your function crashed. Stop Testing.\n\033[0m");
	printf("\033[38;5;226mYou can check \"output.txt\" for more information \n\n\033[0m");
	
    exit(signum);
}

int main(int argc, char **argv)
{
	int only_basic = FALSE;
	int only_everything = FALSE;
	// system("clear");
	if(argc >= 2)
	{
		if (argv[1][0] == 's')
			short_output = 1;
		if (argv[1][0] == 'b')
			only_basic = TRUE;
		if (argv[1][0] == 'm')
			only_everything = TRUE;
	}
	// printf("\xF0\x9F\x98\x8A\n");
    FILE *file = fopen(filename, "w");
	signal(SIGSEGV, segfault_handler);
    
    if (file != NULL) {
        freopen("output.txt", "w", stdout);
	
		if (only_everything)
			print_test_everything();
		else
		{
			if(only_basic)
			{
				print_test_basic();
				print_test_basic_extended();
			}
			else
			{
				print_test_basic();
				print_test_basic_extended();
				print_test_number();
				print_test_minus();
				print_test_dot();
				print_test_zero();
				print_test_mix();
				print_test_bonus();
				if (short_output)
					print_test_everything();
			}
		}

		// print_test_l("%u", MAX_LONG);

		// print_test_d("%010.5d", 55);
		// print_test_d("%9%", 0);
		// print_test_d("%9s%%", 0);

		printf("#END OF TESTS\n#END OF TESTS\n#END OF TESTS\n");

		freopen("/dev/tty", "w", stdout);
        fclose(file);
    } else {
        printf("Failed to open the file.\n");
    }

	char *s = readFileToString(filename);

	bettercompare(s);
	fflush(stdout);
	free(s);
    return 0;
}
void	printresult(int testnb, int errornb)
{
	double percentage = (((testnb - errornb) * 1.0) / (testnb * 1.0)) * 100;
	if(percentage >= 100)
	{
		printf("\n\033[1;4;38;5;40m#All %3d tests OK, Congrats !\033[0m", testnb);
	}
	else
	{
		printf("\n\033[1;4;31m#You passed %d out of %d tests (%.2f%%)\033[0m", testnb - errornb, testnb, percentage);
	}
}

/*
Short answer will print only error and up to 20 errors at a time.
Will also print the percentage off success per category
*/
void bettercompare(char *s)
{
	char **tab = split(s, '\n');
	int index = 0;
	char *s0 = tab[0];
	char *s1 = tab[1];
	char *s2 = tab[2];
	int is_strs_equal = 0;
	int is_return_equal = 0;
	int errornb = 0;
	int errorSUM = 0;
	int TotalTest = 0;

	int twidth = getTerminalWidth();

	print_Header1(twidth);

	while(1)
	{
		if (*s0 == '#')
		{
			if(strncmp(s0, "#TEST", 4) == 0)
			{
				if(short_output == FALSE)
				{
					printf("\n");
					print_Header3(s0);
					printf("\n");
				}
			}
			else
			{
				if(testnb)
				{
					printresult(testnb, errornb);
					testnb = 0;errornb = 0;
				}
				print_Header2(twidth, s0);
			}
			if(strncmp(s0, "#END", 4) == 0)
			{
				printresult(TotalTest, errorSUM);
				printf("\n");
				break;
			}
		}
		else if (strncmp(s0, "input :", 5) == 0)
		{
			is_strs_equal = (strncmp(s1, s2, (strlen(s1) - 3)) == 0);
			is_return_equal = (strcmp(s1 + (strlen(s1) - 3), s2 + (strlen(s2) - 3)) == 0);
			if(is_strs_equal && is_return_equal){
				if(short_output == FALSE)
					printf("\033[38;5;40m%d.OK \033[0m", testnb);
			}
			else
			{
				if (short_output == FALSE)
					printf("\n\033[1;31m%d.KO \033[0m", testnb);
				if (errorSUM < MAX_ERROR_NB && short_output == FALSE)
				{
					if(is_strs_equal == 0){
						printf("\033[31m The output is wrong. \033[0m");
						if(is_return_equal == 1)
							printf("\033[38;5;40m But the return value is correct.\033[0m");
					}
					if(is_return_equal == 0){
						printf("\033[31m The return value is wrong.\033[0m");
						if(is_strs_equal == 1)
							printf("\033[38;5;40m But the output value is correct.\033[0m");
					}

					if(is_return_equal == 0 || is_strs_equal == 0)
						printf("\n%s", s0);
					if(is_strs_equal == 0)
					{
						printf("\nexpected %.*s\n", (int)(strlen(s1) - 3), s1);
						printf(  "output   %.*s\n", (int)(strlen(s2) - 3), s2);
					}
					if(is_return_equal == 0)
					{
						printf("\nexpected %s\n", s1 + (strlen(s1) - 3));
						printf(  "output   %s\n", s2 + (strlen(s2) - 3));
					}
				}
				errornb++;
				errorSUM++;
			}
			testnb++;
			TotalTest++;
			if(errorSUM == MAX_ERROR_NB && short_output == FALSE)
			{
				short_output = TRUE;
				printf("\033[38;5;226m\n\nMaximum error number (20) reached, stop printing output to not overflow the terminal. (test will continue in short format)\n\033[0m");
				// break;
			}
		}
		index++;
		s0 = tab[index];
		s1 = tab[index + 1];
		s2 = tab[index + 2];
	}
	int i = 0;
	while(tab[i])
		free(tab[i++]);
	free(tab);
	printf("\n");
}

char *readFileToString(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(fileSize + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if ((long)bytesRead != fileSize) {
        fprintf(stderr, "Error reading file %s\n", filename);
        fclose(file);
        free(buffer);
        return NULL;
    }
    buffer[bytesRead] = '\0';

    fclose(file);
    return buffer;
}

void print_test_mix()
{
	char *s = "%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%d%%%s%%%d%%%i%%%u%%%x%%%X%%%% %d%%";
	printf("#TEST Mix\n");
	printf("input : mix\n");
	printf("|");
	printf("|%4d\n", printf(s, 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
	printf("|");fflush(stdout);
	printf("|%4d\n", ft_printf(s, 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
}

void print_test_d(char *s, int input)
{
	printf("input : (\"%s\", %d)\n", s, input);
	printf("|");
	printf("|%4d\n", printf(s, input));
	printf("|");fflush(stdout);
	printf("|%4d\n", ft_printf(s, input));
}

void print_test_s(char *s, char *input)
{
	printf("input : (\"%s\", %s)\n", s, input);
	printf("|");
	printf("|%4d\n", printf(s, input));
	printf("|");fflush(stdout);
	printf("|%4d\n", ft_printf(s, input));
}

void print_test_p(char *s, const void *input)
{
	printf("input : (\"%s\", %p)\n", s, input);
	printf("|");
	printf("|%4d\n", printf(s, input));
	printf("|");fflush(stdout);
	printf("|%4d\n", ft_printf(s, input));
}

void print_test_l(char *s, long input)
{
	printf("input : (\"%s\", %ld)\n", s, input);
	printf("|");
	printf("|%4d\n", printf(s, input));
	printf("|");fflush(stdout);
	printf("|%4d\n", ft_printf(s, input));
}