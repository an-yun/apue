#include "../include/apue.h"
#include <sys/wait.h>

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int stauts;

    printf("%% ");// prompt
    while(fgets(buf, MAXLINE, STDIN_FILENO) != NULL)
    {
        int cmd_len = strlen(buf);
        if(buf[cmd_len-1] == '\n')// replace \n with end char
           buf[cmd_len-1] = 0;
        if((pid=fork()) < 0)
        {
            err_sys("fork error");
        }
        else if ( pid == 0 )// child process
        {
            execlp(buf, buf, (char *)0);

        }
    }
}
