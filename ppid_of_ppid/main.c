#include <stdio.h>


// int main (void) {
//     int pid = getpid();

//     while (pid > 1) {

//         char filename[1000];
//         sprintf(filename, "/proc/%d/stat", pid);
//         FILE *f = fopen(filename, "r");

//         int unused;
//         char comm[1000];
//         char state;
//         int ppid;
//         fscanf(f, "%d %s %c %d", &unused, comm, &state, &ppid);

//         printf("%d\n", ppid);

//         pid = ppid;
//     }


//     return 0;
// }


int main (void) {
    int pid = getppid();

    while (pid > 1) {

        char filename[1000];
        sprintf(filename, "/proc/%d/stat", pid);
        FILE *f = fopen(filename, "r");

        int unused;
        char comm[1000];
        char state;
        int ppid;
        fscanf(f, "%d %s %c %d", &unused, comm, &state, &ppid);

        printf("%d\n", ppid);

        pid = ppid;
    }


    return 0;
}