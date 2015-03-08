#include <string.h>
#include "fileiostring.h"
#include "treenode.h"

FILE *ifp;
char fileName[25];

int main() {
   // while(mainMenu() != 3);
//    char *a = malloc(2*sizeof(char));
//    *a = 'a';
//    *(a+1) = '\0';
//    *(a+2) = 'c';
//    *(a+3) = 'd';
//
//    printf("zzzzzzz: %s\n", a);
//    testz(a);
//
//    char *x = "a";
//    char *r = "aa";
//    int res = strcmp(x,r);
//    printf("fdfd: %d\n", res);
    testfile();
    return 0;
}

void testz(void* p){
    printf("zzzzzzz: %s\n", (char*)p);
}

void testfile() {

    printf(">>>opening file: %s\n", fileName);
    fflush(stdout);
    ifp = open_file("tiny.txt", "r");
    if (!ifp) {
        printf("Failed to open file\n");
        fflush(stdout);
        return;
    }

    getString(ifp, 100);
//
//    char *strBuffer = getString(ifp,10);
//
//    char *pch;
//
//    pch = strtok (strBuffer," ,.-");
//    while (pch != NULL){
//        printf ("%s\n",pch);
//        pch = strtok (NULL, " ,.-");
//    }
//
//
    if (close_file(ifp))
        printf(">>>File closed: %s\n", fileName);
}

char *getString(FILE* fp, int size){
    TreeBase *tree_base = new_base(comp_strs, clean_strs, print_strs);
    const char *invalid_chrs = "()!\?\"";
    const char *space_chrs = "\f\n\r\t\v ";

    char *fileStr = malloc(size*sizeof(char));
   // int totalSize = size;
    char temp;
    if(!fileStr)
        return NULL;
//tolower()
    int cnt = 0;
    char *toInsert;
    while((temp = fgetc(fp)) != EOF){
        if (strchr(invalid_chrs, temp))
            continue;
        if (strchr(space_chrs, temp)){
            printf("%.*s\n", cnt, fileStr);
            toInsert = malloc(cnt*sizeof(char) + 1);
            memcpy(toInsert, fileStr, cnt * sizeof(char));
            *(toInsert + cnt) = '\0';
            insert(tree_base, toInsert);
            cnt = 0;
            continue;
        }
        temp = tolower((unsigned char)temp);
        *(fileStr + cnt) = temp;
      //  if(cnt == totalSize)
      //  *(fileStr + cnt) = temp;
        cnt++;
    }
    printTree(tree_base);
    return 0;

//    if ( i >= buffer_size )
//    {
//        temp = realloc(buffer, buffer_size*2);
//        if (!temp)
//            reportError();
//        buffer_size *= 2;
//        buffer = temp;
//    }
//    int ch;
//    size_t len = 0;
//    str = realloc(NULL, );
//
//    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
//        str[len++]=ch;
//        if(len==size){
//            str = realloc(str, sizeof(char)*(size+=16));
//            if(!str)return str;
//        }
//    }
//    str[len++]='\0';
//    return realloc(str, sizeof(char)*len);
    return NULL;
}


void testa() {
    int *a = calloc(1, (sizeof(int)));
    if (a) {
        printf("allocated success\n");
        fflush(stdout);
    }

    *a = 6969;
    free(a);
    a = NULL;
    if (!a) {
        bool g = (a == NULL);
        printf("%s\n", g ? "a is null" : "a is not null");
        fflush(stdout);
    }

    a = calloc(1, (sizeof(int)));
    *a = 6969;
    int *b = a;
    a = calloc(1, (sizeof(int)));
    *a = 1324;
    printf("a: %d, b: %d\n", *a, *b);
    fflush(stdout);
    free(a);
    free(b);
}

void testy() {
    //
    int *a, *b;
    a = malloc(sizeof(int));
    b = malloc(sizeof(int));
    *a = 12;
    b = a;
    printf("a is :%d, b is :%d\n", *a, *b);
    free(a);
    a = NULL;
}

void testx() {

    TreeBase *ptr_tree_base_int_1;
    int *int_arr_ptr;
    int arr_size = 25;

    int_arr_ptr = calloc(arr_size, (sizeof(int)));
    ptr_tree_base_int_1 = new_base(comp_ints, clean_ints, print_ints);
    if (!ptr_tree_base_int_1 || !int_arr_ptr) {
        printf("Error allocating memory in test Setup\n");
        fflush(stdout);
        assert(NULL);
    }
    for (int i = 0; i < arr_size; ++i) {
        int r = rand() % 20000;
        *(int_arr_ptr + i) = r;
    }

    printf("_________START_EMPTY_TREE/TREEBASE_PRINT/FREETREE_TEST__________\n");
    fflush(stdout);

    int *ptr;
    for (int i = 0; i < arr_size; i++) {
        ptr = malloc(sizeof(int));
        memcpy(ptr, (int_arr_ptr + i), sizeof(int));
        insert(ptr_tree_base_int_1, ptr);
    }
    // should print tree
    printf("!!!Next lines has to be tree printed out\n");
    fflush(stdout);
    printTree(ptr_tree_base_int_1);
    fflush(stdout);
    printf("_____________________\n");
    fflush(stdout);

    // No output
    freeTree(ptr_tree_base_int_1);
    // should print cannot free empty tree
    printf("!!!Next line has to be:\"cannot free empty tree\"\n");
    fflush(stdout);
    freeTree(ptr_tree_base_int_1);
    fflush(stdout);

    // should print cannot print empty tree
    printf("!!!Next line has to be:\"cannot print empty tree\"\n");
    fflush(stdout);
    printTree(ptr_tree_base_int_1);
    fflush(stdout);
    printf("_____________________\n");
    fflush(stdout);
    //ptr_tree_base_int_1->size
    free(ptr_tree_base_int_1);
    ptr_tree_base_int_1 = NULL;

    // should print cannot free empty tree base
    printf("!!!Next line has to be:\"cannot free empty tree base\"\n");
    fflush(stdout);
    freeTree(ptr_tree_base_int_1);
    fflush(stdout);

    // should print cannot print empty tree base
    printf("!!!Next line has to be:\"cannot print empty tree base\"\n");
    fflush(stdout);
    printTree(ptr_tree_base_int_1);
    fflush(stdout);
    printf("_____________________\n");
    fflush(stdout);

    free(int_arr_ptr);
    int_arr_ptr = NULL;
    printf("freeing the array...\n");
    fflush(stdout);


    if (ptr_tree_base_int_1) {
        freeTree(ptr_tree_base_int_1);
        free(ptr_tree_base_int_1);
        ptr_tree_base_int_1 = NULL;
    }
    if (int_arr_ptr) {
        free(int_arr_ptr);
        int_arr_ptr = NULL;
    }

    printf("________END_____________\n");
    fflush(stdout);
}


int mainMenu(void) {
    int option = -1;
    system("clear");
    printf("Welcome\n");
    printf("1. Enter file name\n");
    printf("2. Run analysis on file\n");
    printf("3. Exit\n");
    printf("Selected file: %s\n", fileName);
    printf("\nOption: ");
    fflush(stdin);
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Please enter file name, that exists in resources dir!\n");
            fflush(stdout);
            fflush(stdin);
            scanf("%s", fileName);
            break;
        case 2:
            runAnalys();
            break;
        case 3:
            printf("All done!\n");
            fflush(stdout);
            break;
        default:
            while (getchar() != '\n');
            break;
    }
    return option;
}

void runAnalys(){

}