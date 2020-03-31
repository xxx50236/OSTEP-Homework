#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int x = 0;

    int rc = fork();

    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("x value in child %d before change\n", x);
        x = 100;
        printf("x value in child %d after change\n", x);    
    } else {
        // parent goes down this path (original process)
        printf("x value in parent %d before change\n", x);
        x = 200;
        printf("x value in parent %d after change\n", x);   
    }
    return 0;
}