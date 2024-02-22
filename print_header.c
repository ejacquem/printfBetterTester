#include "printftest.h"

#define ITALIC "\x1B[3m"
#define RESET "\x1B[0m"
#define UNDERLINE "\x1B[4m"
#define YELLOW "\033[38;5;226m"

#define BLUE1     "\x1b[38;5;69m"
#define BLUE2     "\x1b[38;5;75m"
#define BLUE3     "\x1b[38;5;81m"
#define BLUE4     "\x1b[38;5;87m"
#define BLUE5     "\x1b[38;5;93m"
#define BLUE6     "\x1b[38;5;99m"

void print_Header1(int terminalWidth)
{
	printf(BLUE4);
	printf("\n");
	printf("@");
	printn('-',terminalWidth - 2);
	printf("@\n");
	printf("|");
	printn(' ',terminalWidth - 2);
	printf("|\n");

    printf("|" BLUE4 "  _____      _       _    __ _______        _             |\n");
    printf("|" BLUE3 " |  __ \\    (_)     | |  / _|__   __|      | |            |\n");
    printf("|" BLUE2 " | |__) | __ _ _ __ | |_| |_   | | ___  ___| |_ ___ _ __  |\n");
    printf("|" BLUE1 " |  ___/ '__| | '_ \\| __|  _|  | |/ _ \\/ __| __/ _ \\ '__| |\n");
    printf("|" BLUE6 " | |   | |  | | | | | |_| |    | |  __/\\__ \\ ||  __/ |    |\n");
    printf("|" BLUE5 " |_|   |_|  |_|_| |_|\\__|_|    |_|\\___||___/\\__\\___|_|    |\n");
    printf("|"       "                                                          |\n");

	printf("|");
	printn(' ',terminalWidth - 2 - 11);
	printf(ITALIC UNDERLINE "By Lucas J" RESET BLUE5 " ");
	printf("|\n");
	printf("@");
	printn('-',terminalWidth - 2);
	printf("@\n");
	
	printf(RESET);
}

void print_Header2(int terminalWidth, char *s)
{
	printf(BLUE4);
	printf("\n\n|");
	printn('-',terminalWidth - 1);
	printf("\n");

	printf("|%s\n|", s);

	printn('-',terminalWidth - 1);
	printf("\n");
	printf(RESET);
}

void print_Header3(int terminalWidth, char *s)
{
	printf(BLUE1);
	printf("\n%s", s);
	printn('-', terminalWidth / 60);
	printf("\n");
	printf(RESET);
}

void printn(char c, int n)
{
	while(n--)
		printf("%c", c);
}

