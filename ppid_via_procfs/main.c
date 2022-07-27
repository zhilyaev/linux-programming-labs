#include <stdio.h>


int main (void) {

    int pid = getpid();

    char filename[1000];
    sprintf(filename, "/proc/%d/stat", pid);
    FILE *f = fopen(filename, "r");

    int unused;
    char comm[1000];
    char state;
    int ppid;
    fscanf(f, "%d %s %c %d", &unused, comm, &state, &ppid);

    printf("%d\n", ppid);
    return 0;
}
