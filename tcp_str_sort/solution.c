#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct sockaddr_in local;

int comp (const void * elem1, const void * elem2){
    char f = *((char*)elem1);
    char s = *((char*)elem2);
    if (f < s) return 1;
    if (f > s) return -1;
    return 0;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Format %s port \n", argv[0]);
        return 1;
    }

    (void) argv;

    int s = socket(AF_INET, SOCK_STREAM, 0);
    // printf("%d\n", s);

    inet_aton("127.0.0.1", &local.sin_addr);
    int port = atoi(argv[1]);
    // printf("port: %d\n", port);

    local.sin_port   = htons(port);
    local.sin_family = AF_INET;

    int result = bind(s, (struct sockaddr*) &local, sizeof(local));
    // printf("result: %d\n", result);

    char buffer[BUFSIZ];


    const char* text = "OFF\n";
    while (true)
    {
        ssize_t length = read(s, buffer, BUFSIZ);
        buffer[length] = 0;
        if (strncmp(buffer, text, sizeof(text)) == 0)
            break;

        qsort(buffer, strlen(buffer), 1, comp);

        write(s, buffer, sizeof(buffer));

        // printf("%s\n", buffer);
    }

    return 0;
}



