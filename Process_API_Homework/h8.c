#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    int p[2];
    char inbuf[16]; 

    if (pipe(p) < 0) {
        exit(1);
    }

    pid_t child_a, child_b;
    child_a = fork();

    if (child_a < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (child_a == 0) {
        // child (new process)
        for (size_t i = 0; i < 3; i++)
        {
            read(p[0], inbuf, 16); 
            printf("%s\n", inbuf);
        }
    } else {
        // parent goes down this path (original process)
        child_b = fork();

        if (child_b < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (child_b == 0) {
            // child (new process)
            write(p[1], "msg1", 16); 
            write(p[1], "msg2", 16); 
            write(p[1], "msg3", 16); 
        }
    }
    return 0;
}