#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    close(STDOUT_FILENO); 
	open("./h2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

    int x = 0;
    int rc = fork();

    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        x += 1;
        printf("write x:%d by child %d\n", x, (int) getpid());
    } else {
        // parent goes down this path (original process)
        x += 1;
        printf("writr x:%d by parent %d\n", x, (int) getpid());
    }
    return 0;
}