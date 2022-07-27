#include <stdio.h>
#include <sys/types.h>
#include <pty.h>
#include <unistd.h>

int main(int argc, char **v) {
    int ptyFD = -1;

    pid_t forkPID = forkpty(&ptyFD, NULL, NULL, NULL);

    if(forkPID < 0) {
        printf("Fork error!\n");
        return -1;
    } else if(forkPID == 0) {
        // we're in the child process
        char* const args[] = { "ls", "/home/lytithwyn", 0 };
        execvp("ls", args);
        printf("Exec error!\n");
        return -2;
    } else {
        // we're still in the parent process

        // We're declaring a buffer size of {buffSize} bytes but a buffer
        // of {buffSize} + 1 bytes because in this case we are ONLY doing string I/O
        // and we know we're going to want to NULL-terminate everything; therefore
        // we make room for the \0 at the end.  If we we're going to be
        // doing binary I/O, we would just have a buffer of {buffSize} bytes.
        size_t buffSize = 1024;
        char buff[buffSize + 1];
        ssize_t bytesRead;

        while((bytesRead = read(ptyFD, (void *)buff, buffSize)) > 0) {
            printf("Read %d bytes\n", bytesRead);
            buff[bytesRead] = '\0';
            printf("%s", buff);
        }

        close(ptyFD);
    }
}