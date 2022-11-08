#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* This should be in cmake */
#include "file-io/include/file-io-posix.h"

int main(int argc, char * argv[]) 
{
    printf("Hello World\r\n");
    if (argc > 1) {
        printf ("Got an Argument here: %s\r\n", argv[1]);
    }
    else {
        printf("No arguments.\r\n");
    }

    int err = 0;
    file_io_struct_t* pReadmeFile = file_io_open("../README.md", true, false, &err);
    if (!pReadmeFile) {
        printf("Open Error: %d", err);
        return 1;
    }
    else {
        printf("Opened File: %s", pReadmeFile->fileName);
    }
    file_io_close(pReadmeFile);

    return 0;
}

