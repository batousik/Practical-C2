#include "treenode.h"

int main(){
	int a,b,c,d,e,f,g;
	a=1;
	b=2;
	c=3;
	d=4;
	e=5;
	f=98;
	g=97;
	TreeBase *tree_base = new_base(comp_ints, clean_int, print_int);
	tree_base->base = new_node(&c);
	tree_base->base->left = new_node(&b);
	tree_base->base->right = new_node(&d);
	tree_base->base->left->left = new_node(&a);
	tree_base->base->right->right = new_node(&e);
	insert(tree_base, &f);
	insert(tree_base, &g);

	printTree(tree_base);
	return 0;
}