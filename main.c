#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <readline/history.h>
#include <limits.h>                        //For HOST_NAME_MAX

char* get_username() {

    uid_t uid = getuid(); //get user id

    struct passwd *pw = getpwuid(uid); // get the passwd struct for that uid
    if (pw == NULL) {
        //pw can fail if the user doesn't exist or due to sys errors
        perror("Error retrieving password info for current user\n");
    }
    return pw;
};

char* get_hostname(buf, sizeof(buf)) {

    if(gethostname(buf, sizeof(buf)) == 0) {
        return buf;
    } else{
        perror("Error retrieving hostname\n");
    }
    return buf;
};


int main()
{
	int close = 1;
    char hostname[HOST_NAME_MAX + 1];  //Buffer to store hostname, +1 for null terminator

	
	while(!close) {
		char* input = readline("> ");
		
	}
	return 0;
}
