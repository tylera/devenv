#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) 
{
    printf("Hello World\r\n");
    if (argc > 1) {
        printf ("Got an Argument here: %s\r\n", argv[1]);
    }
    else {
        printf("No arguments.\r\n");
    }
    return 0;
}