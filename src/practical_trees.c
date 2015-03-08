#include <string.h>
#include "fileiostring.h"
#include "treenode.h"

int main(){
	testa();
	testx();
	testfile();
//	for (int i = 0; i < 10; ++i) {
//		int r = rand() % 20000;
//		*(ptr + i) = r;
//		printf("[i:%d, v:%d, a:%p]", i, *(ptr + i), ptr+i);
//		fflush(stdout);
//	}
//	printf("\n");
//	printf("[v:%d, a:%p]", *(ptr2), ptr2);
//	printf("\n");
//	*ptr2=5;
//	printf("[v:%d, a:%p]", *(ptr2), ptr2);
//	printf("\n");
//	for (int i = 0; i < 10; ++i) {
//		printf("[i:%d, v:%d, a:%p]", i, *(ptr + i), ptr+i);
//	}
//	printf("\n");

//	free(ptr2);
//	free(ptr);
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

void testfile(){
	printf("_____________TESTSING FILE______\n");
	fflush(stdout);

	char fname[100] = "../resource/tiny.txt";
	char fmode[3] = "r";
	FILE *ifp = open_file(&fname, &fmode);
	if (!ifp){
		printf("Failed to open file\n");
		fflush(stdout);
		return;
	}
	close_file(ifp);
}


void testa(){
	int *a = calloc(1,(sizeof(int)));
	if (a){
		printf("allocated success\n");
		fflush(stdout);
	}

	*a = 6969;
	free(a);
	a = NULL;
	if (!a) {
		bool g = (a == NULL);
		printf("%s\n", g ? "a is null" : "a is not null");
		fflush(stdout);
	}

	a = calloc(1,(sizeof(int)));
	*a = 6969;
	int *b = a;
	a = calloc(1,(sizeof(int)));
	*a = 1324;
	printf("a: %d, b: %d\n",*a,*b);
	fflush(stdout);
	free(a);
	free(b);
}
void testx(){

	TreeBase *ptr_tree_base_int_1;
	int *int_arr_ptr;
	int arr_size = 25;

	int_arr_ptr = calloc(arr_size, (sizeof(int)));
	ptr_tree_base_int_1 = new_base(comp_ints, clean_ints, print_ints);
	if(!ptr_tree_base_int_1 || !int_arr_ptr) {
		printf("Error allocating memory in test Setup\n");
		fflush(stdout);
		assert(NULL);
	}
	for (int i = 0; i < arr_size; ++i) {
		int r = rand() % 20000;
		*(int_arr_ptr+i) = r;
	}

	printf("_________START_EMPTY_TREE/TREEBASE_PRINT/FREETREE_TEST__________\n");
	fflush(stdout);

	int *ptr;
	for (int i = 0; i < arr_size; i++) {
		ptr = malloc(sizeof(int));
		memcpy(ptr, (int_arr_ptr + i), sizeof(int));
		insert(ptr_tree_base_int_1, ptr);
	}
	// should print tree
	printf("!!!Next lines has to be tree printed out\n");
	fflush(stdout);
	printTree(ptr_tree_base_int_1);
	fflush(stdout);
	printf("_____________________\n");
	fflush(stdout);

	// No output
	freeTree(ptr_tree_base_int_1);
	// should print cannot free empty tree
	printf("!!!Next line has to be:\"cannot free empty tree\"\n");
	fflush(stdout);
	freeTree(ptr_tree_base_int_1);
	fflush(stdout);

	// should print cannot print empty tree
	printf("!!!Next line has to be:\"cannot print empty tree\"\n");
	fflush(stdout);
	printTree(ptr_tree_base_int_1);
	fflush(stdout);
	printf("_____________________\n");
	fflush(stdout);
	//ptr_tree_base_int_1->size
	free(ptr_tree_base_int_1);
	ptr_tree_base_int_1 = NULL;

	// should print cannot free empty tree base
	printf("!!!Next line has to be:\"cannot free empty tree base\"\n");
	fflush(stdout);
	freeTree(ptr_tree_base_int_1);
	fflush(stdout);

	// should print cannot print empty tree base
	printf("!!!Next line has to be:\"cannot print empty tree base\"\n");
	fflush(stdout);
	printTree(ptr_tree_base_int_1);
	fflush(stdout);
	printf("_____________________\n");
	fflush(stdout);

	free(int_arr_ptr);
	int_arr_ptr = NULL;
	printf("freeing the array...\n");
	fflush(stdout);


	if (ptr_tree_base_int_1){
		freeTree(ptr_tree_base_int_1);
		free(ptr_tree_base_int_1);
		ptr_tree_base_int_1 = NULL;
	}
	if(int_arr_ptr){
		free(int_arr_ptr);
		int_arr_ptr = NULL;
	}

	printf("________END_____________\n");
	fflush(stdout);
}