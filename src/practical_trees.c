#include "treenode.h"

int main(){
	int x = 7;
	TreeBase *tree_base = new_base(comp_ints, clean_int, print_int);
	tree_base->base->value = &x;
	tree_base->base->left = tree_base->base;
	tree_base->base->right = tree_base->base;
	
	printTree(tree_base);
	return 0;
}