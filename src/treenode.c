#include "treenode.h"

// It is used to order 
// nodes of your tree. 
// This comparison function 
// should return -1,0 or 1 (like strcmp)
int comp_ints (void* p1, void* p2) {
	 return *(int*)p1 == *(int*)p2;
}

void clean_int(){
 		
}

void print_int(){
	
}

typedef void(*print_fn)(void*);

int sum(int* a, int* b){
	return *a+*b;
}

TreeBase* new_base(comp_fn co, clean_fn cl, print_fn p){
  TreeBase *temp = (*TreeBase) malloc (sizeof (TreeBase));
  temp->base = (*TreeNode) malloc (sizeof (TreeNode));
  temp->comp = co;
  temp->clean = cl;
  temp->print = p;
  return temp;
}

void printTree(TreeBase* tree){
	// TreeBase* temp = tree;
	// if (tree != NULL) {
	//   temp
 //      printTree(temp->left);
 //      printf("%p", temp->value);
 //      printTree(temp->right);
 //   }
}