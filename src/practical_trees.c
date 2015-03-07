#include "treenode.h"

int main(){
//	int *ptr = malloc(10*(sizeof(int)));
//	*ptr = 0;
//	printf("%d", *ptr);
//	ptr = NULL;
//	free(ptr);
	int *ptr = calloc(10,(sizeof(int)));
	int *ptr2 = (ptr+5);
	*ptr2=5;
	free(ptr2);
	free(ptr);
//	printf("START\n");
//	TreeBase  *ptr_tree_base_int_1;
//	TreeNode  *ptr_tree_node;
////	int *int_arr_ptr;
////	int arr_size = 100;
//	int a,b,c,d,e;
//	a = 5;
//	b = 6;
//	c = 7;
//	d = 8;
//	e = 1;
//	ptr_tree_base_int_1 = new_base(comp_ints, clean_ints, print_ints);
//	insert(ptr_tree_base_int_1, &b);
//	insert(ptr_tree_base_int_1, &a);
//	insert(ptr_tree_base_int_1, &c);
//	insert(ptr_tree_base_int_1, &d);
//	insert(ptr_tree_base_int_1, &e);
//	ptr_tree_node = ptr_tree_base_int_1->base;
//	printNode(ptr_tree_node);
//	printNode(ptr_tree_node->left);
//	printNode(ptr_tree_node->right);
//	printTree(ptr_tree_base_int_1);
//	getchar();
//	printf("END\n");
//	int_arr_ptr = malloc(arr_size*sizeof(*int_arr_ptr));
//	ptr_tree_base_int_1 = new_base(comp_ints, clean_ints, print_ints);
//	ptr_tree_node = new_node(NULL,NULL,NULL);
//	if(int_arr_ptr==NULL || ptr_tree_base_int_1==NULL || ptr_tree_node==NULL) {
//		printf("Error allocating memory in test Setup");
//		assert(NULL);
//	}
//
//	for (int i = 0; i < arr_size; ++i) {
//		int r = rand() % 20000;
//		*(int_arr_ptr + i) = r;
//	}
//
//	//ck_assert_int_eq(freeTree(ptr_tree_base_int_1), true);
//	if (ptr_tree_base_int_1 == NULL)
//		printf("x1");
//		//ck_abort_msg("tree_base was NULL");
//	if (ptr_tree_base_int_1->base != NULL)
//		printf("x2");
//	//	ck_abort_msg("tree_base->base was NULL, expected NULL");
////
//	printf("%d\n", insert(ptr_tree_base_int_1, &a));
//	if (ptr_tree_base_int_1->base == NULL)
//		printf("x3");
//		//ck_abort_msg("tree_base->base was NULL, expected assigned node");
//	printf("%d\n", ptr_tree_base_int_1->size);
//	if (ptr_tree_base_int_1->base->left != NULL && ptr_tree_base_int_1->base->right != NULL)
//		printf("x4\n");
//		//ck_abort_msg("tree_base->base->children wasnt NULL, expected NULL");
//	printf("%d\n", insert(ptr_tree_base_int_1, &b));
//	printf("%d=%d\n", *(int*)(ptr_tree_base_int_1->base->right->value), 6);


	return 0;
}