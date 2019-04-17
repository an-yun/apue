#include "apue.h"
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if(argc == 2)
    {
        if((dp = opendir(argv[1])) == NULL)
            err_sys("can't open %s", argv[1]);
    }
    else
    {
         if((dp = opendir(".")) == NULL)
            err_sys("can't open .");

    }
    while( (dirp = readdir(dp)) != NULL )
        printf("%s\n", dirp->d_name);
    closedir(dp);
    exit(0);
}
