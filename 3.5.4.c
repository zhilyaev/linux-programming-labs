#include <stdio.h>
#include <unistd.h>

int main(int c, char **v)
{
    FILE *fp;
    fp = popen("cat /proc/*/status", "r");
}
