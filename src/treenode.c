#include "treenode.h"

// It is used to order 
// nodes of your tree. 
// This comparison function 
// should return -1,0 or 1 (like strcmp)
int comp_ints (void* p1, void* p2) {
	 return *(int*)p1 == *(int*)p2;
}

void clean_int(void* p){
 		
}

void print_int(void* p){
	printf("%d\n", *(int*)p);
}

int sum(int* a, int* b){
	return *a+*b;
}

TreeBase* new_base(comp_fn co, clean_fn cl, print_fn p){
  TreeBase *temp = (TreeBase*) malloc (sizeof (TreeBase));
  temp->base = (TreeNode*) malloc (sizeof (TreeNode));
  temp->comp = co;
  temp->clean = cl;
  temp->print = p;
  return temp;
}

TreeNode* new_node(void* value){
	TreeNode *temp = (TreeNode*) malloc (sizeof (TreeNode));
	temp->left = NULL;
	temp->right = NULL;
	temp->value = value;
	return temp;
}

void printTree(TreeBase* tree){
	if (tree != NULL) {
	  /* set current to root of binary tree */
	  TreeNode *current_node = tree->base;
	  StackNode *stack = NULL;
	  int done = 0;
	 
	  while (!done) {
	    if(current_node !=  NULL) {
	      push(&stack, current_node);                                               
	      current_node = current_node->left;  
	    } else {
	      if (stack != NULL) {
	        current_node = pop(&stack);
	        tree->print(current_node->value);
	 		current_node = current_node->right;
	      }
	      else
	        done = 1;
	    }
	  } 
   }
}