
#include "fileiostring.h"

#include <stdlib.h>

// method to wrap open file command
FILE *open_file(char *f_rel_name, char *mode){
    FILE *temp_file;
    temp_file = fopen(f_rel_name, mode);
    if (temp_file == NULL) {
//        int path_size = 200;
//        char resolved_path[path_size];
//        realpath(f_rel_name, resolved_path);
//        printf("OPENFILE: error, check if file exists or not r/w protected at path:\n");
//        fflush(stdout);
//        printf("\t%s\n", resolved_path);
//        fflush(stdout);
        return NULL;
    }
    return temp_file;
}

// method to close file
bool close_file(FILE *fp){
    fclose(fp);
    fp = NULL;
    if (!fp)
        return true;
    printf("CLOSEFILE: error\n");
    fflush(stdout);
    return false;

}

// method to write to file,
// depends on what mode file was opened with
bool write_file(FILE *fp){
    return true;
}







