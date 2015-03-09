
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

// parsing file to tree
TreeBase *getParsedFile(FILE* fp, int size){
    TreeBase *tree_base = new_base(comp_strs, clean_strs, print_strs);
    const char *invalid_chrs = "*-_.,()!\?\"";
    const char *space_chrs = "\f\n\r\t\v ";
    int totalSize = size;
    char *fileStr = malloc(totalSize*sizeof(char));
    char temp;
    char temp1;
    char *tempExtender;
    if(!fileStr)
        return NULL;
    int cnt = 0;
    char *toInsert;
    while((temp = fgetc(fp)) != EOF){
        if (strchr(invalid_chrs, temp))
            continue;
        if (strchr(space_chrs, temp)){
            if(strchr(space_chrs, temp1)){
                cnt = 0;
                temp1 = temp;
                continue;
            }
            toInsert = malloc((1+cnt)*sizeof(char));
            memcpy(toInsert, fileStr, cnt * sizeof(char));
            *(toInsert + cnt) = '\0';
            insert(tree_base, toInsert);
            cnt = 0;
            temp1 = temp;
            continue;
        }

        if (cnt >= totalSize){
            totalSize+=size;
            tempExtender = realloc(fileStr, totalSize);
            fileStr = tempExtender;
        }
        temp = tolower((unsigned char)temp);
        *(fileStr + cnt) = temp;
        temp1 = temp;
        cnt++;
    }
    return tree_base;
}

TreeBase *retrieveTreeFromFile(char *file_name, char *mode) {
    printf(">>>opening file: %s\n", file_name);
    fflush(stdout);
    FILE *ifp = open_file(file_name, mode);
    if (!ifp) {
        printf("Failed to open file\n");
        fflush(stdout);
        return NULL;
    }
    TreeBase *t = getParsedFile(ifp, 10000);
    if (close_file(ifp))
        printf(">>>File closed: %s\n", file_name);

    return t;
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
bool write_file(FILE *fp, char *to_write){
    return true;
}







