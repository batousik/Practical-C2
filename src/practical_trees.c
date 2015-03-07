#include "treenode.h"

int main(){
	TreeBase tree_base_int_1, *ptr_tree_base_int_1;
	TreeNode tree_node, *ptr_tree_node;
	int *int_arr_ptr;
	int arr_size = 100;
	int a,b;
	a = 5;
	b = 6;
	int_arr_ptr = malloc(arr_size*sizeof(*int_arr_ptr));
	ptr_tree_base_int_1 = new_base(comp_ints, clean_ints, print_ints);
	ptr_tree_node = new_node(NULL,NULL,NULL);
	if(int_arr_ptr==NULL || ptr_tree_base_int_1==NULL || ptr_tree_node==NULL) {
		printf("Error allocating memory in test Setup");
		assert(NULL);
	}

	for (int i = 0; i < arr_size; ++i) {
		int r = rand() % 20000;
		*(int_arr_ptr + i) = r;
	}

	//ck_assert_int_eq(freeTree(ptr_tree_base_int_1), true);
	if (ptr_tree_base_int_1 == NULL)
		printf("x1");
		//ck_abort_msg("tree_base was NULL");
	if (ptr_tree_base_int_1->base != NULL)
		printf("x2");
	//	ck_abort_msg("tree_base->base was NULL, expected NULL");
//
	printf("%d\n", insert(ptr_tree_base_int_1, &a));
	if (ptr_tree_base_int_1->base == NULL)
		printf("x3");
		//ck_abort_msg("tree_base->base was NULL, expected assigned node");
	printf("%d\n", ptr_tree_base_int_1->size);
	if (ptr_tree_base_int_1->base->left != NULL && ptr_tree_base_int_1->base->right != NULL)
		printf("x4\n");
		//ck_abort_msg("tree_base->base->children wasnt NULL, expected NULL");
	printf("%d\n", insert(ptr_tree_base_int_1, &b));
	printf("%d=%d\n", *(int*)(ptr_tree_base_int_1->base->right->value), 6);


	return 0;
}