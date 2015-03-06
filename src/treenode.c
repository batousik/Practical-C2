#include "treenode.h"

// returns -1 if p1<p2, 0 if p1==p2, 1 if p1>p2,
int comp_ints (void* p1, void* p2) {
	int res = (*(int*)p1 - *(int*)p2);
	return (res<0)?-1:(res>0)?1:0;
}

void clean_int(void* p){
 		
}

void print_int(void* p){
	printf("%d\n", *(int*)p);
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

void insert(TreeBase* tree, void* data){
	if (tree != NULL && data != NULL) {
		/* set current to root of binary tree */
		TreeNode *current_node = tree->base;
		int done = 0;
		while(!done){
			int res = tree->comp(data, current_node->value);
			printf("res:%d, newval:%d, curval:%d\n", res, *(int*)data, *(int*)current_node->value);
			switch (res){
				case -1:
					if (current_node->left != NULL) {
						current_node = current_node->left;
					} else {
						current_node->left = new_node(data);
						done = 1;
					}
					break;
				case 0:
					// value exists!!!
					done = 1;
					break;
				case 1:
					if (current_node->right != NULL){
						current_node = current_node->right;
					} else {
						current_node->right = new_node(data);
						done = 1;
					}
					break;
				default:
					// should never be reached
					break;
			}
		}
	}
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