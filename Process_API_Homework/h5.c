#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    pid_t parent = getpid();
    int rc = fork();
   
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        // int wc = wait(NULL); not work
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        sleep(2);
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello, I am parent of %d (pid:%d)\n", wc, (int) getpid());
    }
    return 0;
}
