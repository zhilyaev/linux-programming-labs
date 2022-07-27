#include <stdio.h>
#include <unistd.h>

int main()
{
    // I know
    system("pidof -c genenv | wc -w");
}
