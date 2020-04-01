#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
   
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        pid_t p = waitpid(0, NULL, WUNTRACED | WCONTINUED);
        if ((int)p == -1) {
            printf("wait errored\n");
        } else { 
            printf("process %d state changed\n", (int)p);
        }
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        sleep(2);
    } else {
        // parent goes down this path (original process)
        printf("hello, I am (pid:%d)\n", (int) getpid());
    }
    return 0;
}
