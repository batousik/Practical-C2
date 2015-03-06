#include "treenode.h"

void push(StackNode **top_ref, TreeNode *tree_node) {
    StackNode *new_sn = (StackNode*) malloc(sizeof(StackNode));
    if(new_sn==NULL) {
        printf("Error allocating memory in creating new node in the stack");
        assert(NULL);
    }
    new_sn->tree_node = tree_node;
    new_sn->next = (*top_ref);
    (*top_ref) = new_sn;
}

TreeNode *pop(StackNode **top_ref) {
    TreeNode *tree_node;
    StackNode *top;
    if(*top_ref == NULL) {
        printf("Stack Underflow \n");
        assert(NULL);
    } else {
        top = *top_ref;
        tree_node = top->tree_node;
        *top_ref = top->next;
        free(top);
        return tree_node;
    }
}