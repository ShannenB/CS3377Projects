/* CS 3377.002 Project 3 sib170130 Shannen Barrameda*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

void mysignalhandler(int signo);

int main(){
        int retVal;
        char command[128];
        int exit;

        while(exit != 0){
                printf("# ");
                scanf("%s", command);

                retVal = system(command);
                printf("%s\n", command);

                if(strcmp(command, "exit") == 0){
                        exit = 0;

                }
        }

        if(retVal < 0){
                printf("error: %s (%d)\n", strerror(errno), errno);
        }

        return 0;
}

void mysignalhandler(int signo){
        printf("Received and ignoring signal %s(%d)\n", strsignal(signo), signo);
        return;

