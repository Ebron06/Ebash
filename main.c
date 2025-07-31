#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{
	int close = 0;
	char* username = getpwuid(getuid());
	
	while(!close) {
		char* input = readline("> ");
		
	}
	return 0;
}:
