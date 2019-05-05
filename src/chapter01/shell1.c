#include "apue.h"
#include <sys/wait.h>

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int stauts;

    printf("%%> ");// prompt
    while(fgets(buf, MAXLINE, stdin) != NULL)
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
            int arg_pos=0;
            char **argv = (char **)malloc(sizeof(char *) * cmd_len);
            int argc = 0;
            while (arg_pos < cmd_len && buf[arg_pos] != 0)
            {
                while(buf[arg_pos] == ' ')
                    ++arg_pos;
                if(buf[arg_pos] != 0)
                {
                    argv[argc++] = buf + arg_pos;
                    while(buf[arg_pos] != ' ' && buf[arg_pos] != 0)
                        ++arg_pos;
                    buf[arg_pos++] = 0;
                }
            }
            argv[argc] = 0;
            execvp(argv[0], argv);
            free(argv);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        if((pid = waitpid(pid, &stauts, 0) < 0))
            err_sys("waitpid error");
        printf("%%> ");
    }
    exit(0);
}
