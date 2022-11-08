#ifndef __file_io_generic_h__
#define __file_io_generic_h__

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_PATH_LEN (1024)

/* TODO: This may be overkill. */
typedef struct file_io_struct
{
    FILE        *fptr;
    ssize_t     curPos;
    bool        isOpen;
    bool        isReadable;
    bool        isWritable;
    int         osError;
    
    char        fileName[MAX_FILE_PATH_LEN];
} file_io_struct_t;

/* TODO: Dox */
bool file_io_posix_open(file_io_struct_t * const p_file_io_struct, char const * const options);
file_io_struct_t * file_io_open(char const * const fileName, bool isReadable, bool isWritable, int * const p_out_OsError);
void file_io_close(file_io_struct_t * const pFileStruct);

#endif /* __file_io_generic_h__ */