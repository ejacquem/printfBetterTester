#include "printftest.h"

#define ITALIC "\x1B[3m"
#define RESET "\x1B[0m"
#define UNDERLINE "\x1B[4m"
#define BOLD "\x1B[1m"
#define YELLOW "\033[38;5;226m"

#define BLUE1     "\x1b[38;5;69m"
#define BLUE2     "\x1b[38;5;75m"
#define BLUE3     "\x1b[38;5;81m"
#define BLUE4     "\x1b[38;5;87m"
#define BLUE5     "\x1b[38;5;93m"
#define BLUE6     "\x1b[38;5;99m"

void print_center(char *color, char *line, int len);
void print_Header1(int terminalWidth)
{
	printf(BLUE4);
	printf("\n\n");
	printf("@");
	printn('-',terminalWidth - 2);
	printf("@\n");
	printf("|");
	printn(' ',terminalWidth - 2);
	printf("|\n");

    // printf("|" BLUE4 "  _____      _       _    __ _______        _             |\n");
    // printf("|" BLUE3 " |  __ \\    (_)     | |  / _|__   __|      | |            |\n");
    // printf("|" BLUE2 " | |__) | __ _ _ __ | |_| |_   | | ___  ___| |_ ___ _ __  |\n");
    // printf("|" BLUE1 " |  ___/ '__| | '_ \\| __|  _|  | |/ _ \\/ __| __/ _ \\ '__| |\n");
    // printf("|" BLUE6 " | |   | |  | | | | | |_| |    | |  __/\\__ \\ ||  __/ |    |\n");
    // printf("|" BLUE5 " |_|   |_|  |_|_| |_|\\__|_|    |_|\\___||___/\\__\\___|_|    |\n");
    // printf("|"       "                                                          |\n");

    print_center(BLUE4, "  _____      _       _    __ _______        _             ",terminalWidth);
    print_center(BLUE3, " |  __ \\    (_)     | |  / _|__   __|      | |            ",terminalWidth);
    print_center(BLUE2, " | |__) | __ _ _ __ | |_| |_   | | ___  ___| |_ ___ _ __  ",terminalWidth);
    print_center(BLUE1, " |  ___/ '__| | '_ \\| __|  _|  | |/ _ \\/ __| __/ _ \\ '__| ",terminalWidth);
    print_center(BLUE6, " | |   | |  | | | | | |_| |    | |  __/\\__ \\ ||  __/ |    ",terminalWidth);
    print_center(BLUE5, " |_|   |_|  |_|_| |_|\\__|_|    |_|\\___||___/\\__\\___|_|    ",terminalWidth);
    print_center(BLUE5, "                                                          ",terminalWidth);

	printf("|");
	printn(' ',terminalWidth - 2 - 11);
	printf(ITALIC UNDERLINE "By Lucas J" RESET BLUE5 " ");
	printf("|\n");
	printf("@");
	printn('-',terminalWidth - 2);
	printf("@\n");
	
	printf(RESET);
}

void print_center(char *color, char *line, int len)
{
	printf("%s",color);

	printf("|");
	printn(' ',(len - 56)/2 - 2);
	printf("%s", line);
	printn(' ',(len - 56)/2 - 2 + len%2);
	printf("|\n");

}

void print_Header2(int len, char *s)
{
	int ispair = (len%2 != (int)strlen(s)%2);
	printf(BLUE4);
	printf("\n\n");
	printf(BOLD);
	printf("o");
	printn('-',len-2);
	printf("o\n");
	printf(RESET BLUE4);

	printf("|");
	printn(' ',(len - strlen(s))/2 - 4);
	printf("- = ");
	printf("%s", s + 1);
	printf(" = -");
	printn(' ',(len - strlen(s))/2 - 5 + ispair);
	printf("|\n");

	printf(BOLD);
	printf("o");
	printn('-',len-2);
	printf("o\n");
	printf(RESET);
}

void print_Header3(char *s)
{
	printf(BLUE1);
	printf(BOLD);
	printf("\n%-25s", s);
	printf(RESET);
}

void printn(char c, int n)
{
	while(n--)
		printf("%c", c);
}

/*

#####
_##__ +1

#####
_###_  +0

######
__##__ +0

######
_###__ +1


*/