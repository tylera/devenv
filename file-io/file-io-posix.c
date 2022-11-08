#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#include "include/file-io-posix.h"

bool file_io_posix_open(file_io_struct_t * const p_file_io_struct, char const * const options)
{
    if (!p_file_io_struct || !options) {
        return false;
    }

    if (p_file_io_struct->fileName[0] == '\0') {
        return false;
    }

    p_file_io_struct->fptr = fopen(p_file_io_struct->fileName, options);
    if (!p_file_io_struct->fptr) {
        p_file_io_struct->osError = (int) errno;
        return false;
    }

    return true;
}

/* TODO: Move to generic. Errno is clumbsy.  */
file_io_struct_t * file_io_open(    char const * const fileName, 
                                    bool isReadable, 
                                    bool isWritable, 
                                    int * const p_out_OsError)
{
    if (!fileName || fileName[0] == '\0') {
        return NULL;
    }

    file_io_struct_t * pFileStruct = (file_io_struct_t*) malloc(sizeof(file_io_struct_t));
    if (!pFileStruct) {
        return NULL;
    }

    memset(pFileStruct, 0, sizeof(*pFileStruct));

    if ( strncpy(   pFileStruct->fileName, fileName, 
                    sizeof(pFileStruct->fileName))  == 
                        &pFileStruct->fileName[MAX_FILE_PATH_LEN])
    {
        *p_out_OsError = -1;
        free (pFileStruct);
        return NULL;
    }

    char options[8] = {0};
    if (isReadable && isWritable) {
        options[0] = 'r';
        options[1] = 'w';
    }
    else if (isReadable && !isWritable) {
        options[0] = 'r';
    }
    else { /* !isReadable && isWritable*/
        options[0] = 'w';
    }

    if (!file_io_posix_open(pFileStruct, options)) {
        *p_out_OsError = pFileStruct->osError;
        free(pFileStruct);
        return NULL;
    }

    return pFileStruct;
}

/* TODO: Pretty bare bones. */
void file_io_close(file_io_struct_t * const pFileStruct)
{
    if (!pFileStruct) {
        return;
    }

    fclose(pFileStruct->fptr);
    free(pFileStruct);
    return;
}
