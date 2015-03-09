#include "treenode.h"

// returns -1 if p1<p2, 0 if p1==p2, 1 if p1>p2,
int comp_ints (void* p1, void* p2) {
	int res = (*(int*)p1 - *(int*)p2);
	return (res<0)?-1:(res>0)?1:0;
}

void clean_ints(void *p){
	if (!p){
		printf("Clean int ptr that is NULL !!\n");
		fflush(stdout);
		return;
	}
	free((int*)p);
	p = NULL;
}

void print_ints(void *p, int *cnt){
	printf("%d\n", *(int*)p);
	fflush(stdout);
}

// returns -1 if p1<p2, 0 if p1==p2, 1 if p1>p2,
int comp_strs (void* p1, void* p2) {
//	A value greater than zero indicates that thefirst character
//	that does not match has a greater value in
//	the first string than in the second,
//	and a value less than zero indicates the opposite.
	int res = strcmp((char*)p1, (char*)p2);
	return (res<0)?-1:(res>0)?1:0;
}

void clean_strs(void *p){
	if (!p){
		printf("Clean str ptr that is NULL !!\n");
		fflush(stdout);
		return;
	}
	char *a = (char*)p;
	free(a);
	a = NULL;
}

void print_strs(void *p, int *cnt){
	printf("(%s,%d)\n", (char*)p, *cnt);
	fflush(stdout);
}

TreeBase* new_base(comp_fn co, clean_fn cl, print_fn p){
	TreeBase *temp = (TreeBase*) malloc (sizeof (TreeBase));
	if(!temp) {
		printf("Error allocating memory in creating new tree base\n");
		fflush(stdout);
		return NULL;
	}
	temp->base = NULL;
	temp->comp = co;
	temp->clean = cl;
	temp->print = p;
	temp->size = 0;
	temp->total_num = 0;
	return temp;
}

TreeNode* new_node(void* value, TreeNode *p_left, TreeNode *p_right){
	TreeNode *temp = (TreeNode*) malloc (sizeof (TreeNode));
	if(!temp) {
		printf("Error allocating memory in creating new tree node\n");
		fflush(stdout);
		return NULL;
	}
	if(!value) {
		printf("Value is null in creating new tree node\n");
		fflush(stdout);
		return NULL;
	}
	temp->left = p_left;
	temp->right = p_right;
	temp->value = value;
	temp->cnt_dublicates = 1;
	return temp;
}

TreeNode* query(TreeBase* tree, void* value){
	// catch NULL data
	if (!tree || !value || !(tree->base)) {
		printf("QUERY: Cannot search null data or use null tree-base or null tree\n");
		fflush(stdout);
		return NULL;
	}
	TreeNode *current_node = tree->base;
	while(true){
		int res = tree->comp(value, current_node->value);
		switch (res){
			case -1:
				if (current_node->left) {
					current_node = current_node->left;
				} else {
					return NULL;
				}
				break;
			case 0:
				return current_node;
			case 1:
				if (current_node->right){
					current_node = current_node->right;
				} else {
					return NULL;
				}
				break;
			default:
				printf("Insert procedure logic fail\n");
				fflush(stdout);
				return false;
		}
	}
	// unreachable code
	return false;
}

bool insert(TreeBase* tree, void* data){
	// catch NULL data
	if (!tree || !data) {
		printf("INSERT: Cannot insert null data or into null tree\n");
		fflush(stdout);
		return false;
	}

	TreeNode *current_node = tree->base;
	// Empty tree condition
	if (!current_node){
		tree->base = new_node(data, NULL, NULL);
		if (!(tree->base))
			return false;
		tree->total_num = tree->total_num + 1;
		tree->size = tree->size + 1;
		return true;
	}
	while(true){
		int res = tree->comp(data, current_node->value);
		switch (res){
			case -1:
				if (current_node->left) {
					current_node = current_node->left;
				} else {
					current_node->left = new_node(data, NULL, NULL);
					if (!(current_node->left))
						return false;
					tree->total_num = tree->total_num + 1;
					tree->size=tree->size+1;
					return true;
				}
				break;
			case 0:
				// value exists!!!
				tree->total_num = tree->total_num + 1;
				current_node->cnt_dublicates = current_node->cnt_dublicates + 1;
				// Pointer passed in will be lost if not freed
				free(data);
				data = NULL;
				return false;
			case 1:
				if (current_node->right){
					current_node = current_node->right;
				} else {
					current_node->right = new_node(data, NULL, NULL);
					if (!(current_node->right))
						return false;
					tree->total_num = tree->total_num + 1;
					tree->size=tree->size+1;
					return true;
				}
				break;
			default:
				printf("Insert procedure logic fail\n");
				fflush(stdout);
				return false;
		}
	}
	// unreachable code
	return false;
}

// return true if tree was freed correctly
// or if it already was free
bool freeTree(TreeBase* tree){
	if (!tree) {
		printf("FREETREE: Cant free empty tree base\n");
		fflush(stdout);
		return true;
	}
	if (!(tree->base)) {
		printf("FREETREE: Cant free empty tree\n");
		fflush(stdout);
		return true;
	}

	TreeNode *current_node = NULL;
	StackNode *stack = NULL;
	push(&stack, tree->base);
	// breadth first traversal
	while (stack) {
		current_node = pop(&stack);
		if (current_node->left)
				push(&stack, current_node->left);
		if (current_node->right)
				push(&stack, current_node->right);
		tree->clean(current_node->value);
		current_node->value = NULL;
		tree->total_num = tree->total_num - current_node->cnt_dublicates;
		tree->size = tree->size - 1;
		free(current_node);
		current_node = NULL;
	}
	tree->base = NULL;
	return (0 == tree->size);
}
// method has two internal tests
// if next value > current and
// if all values were visited
bool printTree(TreeBase *tree){
	void *previous = NULL;
	int cnt_tasks = 0;
	if (!tree) {
		printf("PRINT: Cannot print empty tree base\n");
		fflush(stdout);
		return false;
	}
	/* set current to root of binary tree */
	TreeNode *current_node = tree->base;
	if (!(tree->base)) {
		printf("PRINT: Cannot print empty tree\n");
		fflush(stdout);
		return false;
	}
	StackNode *stack = NULL;
	while (true) {
		if(current_node) {
			push(&stack, current_node);
			current_node = current_node->left;
		} else {
			if (stack) {
				current_node = pop(&stack);
				if (cnt_tasks > 1) {
					if (tree->comp(previous, current_node->value) != -1) {
						printf("PRINTTREE: Invalid BST\n");
						fflush(stdout);
						assert(NULL);
					}
				}
				previous = current_node->value;
				tree->print(current_node->value, &current_node->cnt_dublicates);
				cnt_tasks++;
				current_node = current_node->right;
			} else {
				return (cnt_tasks == tree->size);
			}
		}
	}
}

void printNode(TreeNode* node) {
	if(node == NULL){
		printf("Node is null\n");
		fflush(stdout);
		return;
	}
	int a,b,c,d,e;
	a = (node->left == NULL)?0:1;
	b = (node->right == NULL)?0:1;
	c = (node->value == NULL)?0:1;
	d = node->cnt_dublicates;
	e = (c!=0)?*(int*)node->value:0;
	printf("L:%d, R:%d, V:%d, D:%d, intV:%d\n", a,b,c,d,e);
	fflush(stdout);
}