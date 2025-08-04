#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <readline/history.h>
#include <limits.h>   


#define PROMPT_MAX      512

char* get_username() {

    uid_t uid = getuid(); //get user id

    struct passwd *pw = getpwuid(uid); // get the passwd struct for that uid
    if (pw == NULL) {
        //pw can fail if the user doesn't exist or due to sys errors
        perror("Error retrieving password info for current user\n");
    }
    return pw->pw_name;
};

char* get_hostname(char* buf, size_t size) {
    
    if(gethostname(buf, sizeof(buf)) == 0) {
        return buf;
    } else{
        perror("Error retrieving hostname");
    }
    return NULL;
};


int main()
{
	int close = 1;
    char hostname[HOST_NAME_MAX + 1];  //Buffer to store hostname, +1 for null terminator

    char* host = get_hostname(hostname, sizeof(hostname));
    char* user = get_username();
    char prompt[PROMPT_MAX];

    //TODO: Change tilda to current working directory
    snprintf(prompt, sizeof(prompt), "%s@%s: ~$ ", user, host);
 
	
	while(close) {
        char *input = readline(prompt);
        printf("you input %s\n", input);
	  //free readline to use again
        free(input);
        input = (char *)NULL;
	}
    //free prompt and related memory
	return 0;
}
