#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 300

int countProc(int pid)
{
    int count = 0;
    char cmd[MAX_SIZE];
    FILE *fd;

    sprintf(cmd, "ps -o %%p --ppid %d", pid);
    fd = popen(cmd, "r");
    fscanf(fd, "%*s");

    int id;
    while(fscanf(fd, "%d", &id) != EOF)
    {
        count++;
        count += countProc(id);
    }

    pclose(fd);

    return count;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Error!\n");
        return 1;
    }

    int pid = atoi(argv[1]);

    int count = countProc(pid) + 1;

    printf("%d\n", count);

    return 0;
}
