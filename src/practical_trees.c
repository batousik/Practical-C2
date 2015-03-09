#include "fileiostring.h"
#include "treenode.h"


FILE *ifp;
char file_name[25];
TreeBase* tree_base;

int main() {
    //while(mainMenu() != 3);
    automatic();
    return 0;
}

int mainMenu(void) {
    int option = -1;
    system("clear");
    printf("Welcome\n");
    printf("1. Enter file name\n");
    printf("2. Retrieve file data\n");
    printf("3. Discrard data\n");
    printf("4. Print count information to stdout\n");
    printf("5. Query data\n");
    printf("6. Print other information to stdout\n");
    printf("7. Exit\n");
    printf("Selected file: %s\n", file_name);
    printf("Data loaded: %s\n", (tree_base == NULL)?"NO":"YES");
    printf("\nOption: ");
    fflush(stdin);
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Please enter file name, that exists in resources dir!\n");
            fflush(stdout);
            fflush(stdin);
            scanf("%s", file_name);
            break;
        case 2:
            printf("Please hold done now, getting data from file\n");
            char str_f[40];
            strcpy (str_f,"../resources/");
            strcat (str_f, file_name);
            tree_base = retrieveTreeFromFile(str_f, "r");
            break;
        case 3:
            freeTree(tree_base);
            free(tree_base);
            tree_base = NULL;
            break;
        case 4:
            printTree(tree_base);
            break;
        case 5:
            printf("Please your query string\n");
            char *query_str = malloc(100*sizeof(char));
            fflush(stdout);
            fflush(stdin);
            scanf("%s", query_str);
            TreeNode *t_node = query(tree_base, query_str);
            tree_base->print(t_node->value, &t_node->cnt_dublicates);
            break;
        case 6:
            printf("Not Implemeted!\n");
            fflush(stdout);
            break;
        case 7:
            printf("All done!\n");
            fflush(stdout);
            break;
        default:
            while (getchar() != '\n');
            break;
    }
    return option;
}

void automatic(){
    char *f_name = "../resource/pride.txt";
    tree_base = retrieveTreeFromFile(f_name, "r");
    printTree(tree_base);
}