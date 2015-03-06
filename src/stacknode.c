#include "treenode.h"

void push(StackNode **top_ref, TreeNode *tree_node) {
  StackNode *new_sn = (StackNode*) malloc(sizeof(StackNode));
  if(new_sn == NULL) {
     printf("Stack Overflow \n");
     getchar();
     exit(0);
  }
  new_sn->tree_node = tree_node;
  new_sn->next = (*top_ref);   
  (*top_ref) = new_sn;
}

TreeNode *pop(StackNode **top_ref) {
  TreeNode *tree_node;
  StackNode *top;
  if(isEmpty(*top_ref)) {
     printf("Stack Underflow \n");
     getchar();
     exit(0);
  } else {
     top = *top_ref;
     tree_node = top->tree_node;
     *top_ref = top->next;
     free(top);
     return tree_node;
  }
}