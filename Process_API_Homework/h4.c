#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    int rc = fork();

    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        char *myargs[3];
        myargs[0] = strdup("/bin/ls");   
        myargs[1] = strdup("./h2"); // 请改成自己文件的绝对路径
        myargs[2] = NULL;           // marks end of array
        execvp(myargs[0], myargs); 
        printf("this shouldn't print out");
    }

    return 0;
}