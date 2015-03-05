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
  TreeBase *temp = malloc (sizeof (TreeBase));
  temp->base = malloc (sizeof (TreeNode));
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

int main(){
	int x = 7;
	TreeBase *tree_base = new_base(comp_ints, clean_int, print_int);
	tree_base->base->value = &x;
	tree_base->base->left = tree_base->base;
	tree_base->base->right = tree_base->base;
	
	// int x,y;
	// x = y = 5;
	// int *px, *py;
	// px = &x;
	// py = &y;
	
	// printf("%p\n", px);

	// int z = sum(px, py );

	// z = comp((void*)px, (void*)py);

	// printf("%d\n", z);
	return 0;
}