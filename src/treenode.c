#include "treenode.h"

// returns -1 if p1<p2, 0 if p1==p2, 1 if p1>p2,
int comp_ints (void* p1, void* p2) {
	int res = (*(int*)p1 - *(int*)p2);
	return (res<0)?-1:(res>0)?1:0;
}

void clean_ints(void* p){
	free(p);
}

void print_ints(void *p){
	printf("%d\n", *(int*)p);
}

TreeBase* new_base(comp_fn co, clean_fn cl, print_fn p){
	TreeBase *temp = (TreeBase*) malloc (sizeof (TreeBase));
	if(temp==NULL) {
		printf("Error allocating memory in creating new tree base");
		return NULL;
	}
	temp->base = NULL;
	temp->comp = co;
	temp->clean = cl;
	temp->print = p;
	temp->size = 0;
	return temp;
}

TreeNode* new_node(void* value, TreeNode *p_left, TreeNode *p_right){
	TreeNode *temp = (TreeNode*) malloc (sizeof (TreeNode));
	if(temp==NULL) {
		printf("Error allocating memory in creating new tree node");
		return NULL;
	}
	temp->left = p_left;
	temp->right = p_right;
	temp->value = value;
	return temp;
}

bool insert(TreeBase* tree, void* data){
	// catch NULL data
	if (tree == NULL || data == NULL) {
		printf("INSERT: Cannot insert null data or into null tree");
		return false;
	}

	TreeNode *current_node = tree->base;
	// Empty tree condition
	if (current_node == NULL){
		tree->base = new_node(data, NULL, NULL);
		tree->size = tree->size + 1;
		return true;
	}
	while(true){
		int res = tree->comp(data, current_node->value);
		switch (res){
			case -1:
				if (current_node->left != NULL) {
					current_node = current_node->left;
				} else {
					current_node->left = new_node(data, NULL, NULL);
					tree->size=tree->size+1;
					return true;
				}
				break;
			case 0:
				// value exists!!!
				return false;
			case 1:
				if (current_node->right != NULL){
					current_node = current_node->right;
				} else {
					current_node->right = new_node(data, NULL, NULL);
					tree->size=tree->size+1;
					return true;
				}
				break;
			default:
				printf("Insert procedure logic fail");
				return false;
		}
	}
	// unreachable code
	return false;
}

bool freeTree(TreeBase* tree){
	if (tree == NULL) {
		printf("FREETREE: Cant free empty tree base");
		return false;
	}

	TreeNode *current_node = NULL;
	StackNode *stack = NULL;

	if (tree->base == NULL) {
		printf("FREETREE: Cant free empty tree");
		return false;
	}
	push(&stack, tree->base);
	// breadth first traversal
	while (true) {
		current_node = pop(&stack);
		if (current_node == NULL)
			return (0 == tree->size);
		if (current_node->left != NULL)
				push(&stack, current_node->left);
		if (current_node->right != NULL)
				push(&stack, current_node->right);
		tree->clean(current_node->value);
		free(current_node);
		tree->size = tree->size - 1;
	}


	return true;
}
// method has two internal tests
// if next value > current and
// if all values were visited
bool printTree(TreeBase *tree){
	void *previous;
	int cnt_tasks = 0;
	if (tree == NULL) {
		printf("PRINT: Cannot print empty tree base");
		return false;
	}
	/* set current to root of binary tree */
	TreeNode *current_node = tree->base;
	if (tree->base == NULL) {
		printf("PRINT: Cannot print empty tree");
		return false;
	}
	StackNode *stack = NULL;
	while (true) {
		if(current_node !=  NULL) {
			push(&stack, current_node);
			current_node = current_node->left;
		} else {
			if (stack != NULL) {
				current_node = pop(&stack);
				previous = current_node->value;
				tree->print(current_node->value);
				cnt_tasks++;
				if (cnt_tasks > 1) {
					if (tree->comp(previous, current_node->value) != -1) {
						printf("PRINTTREE: Invalid BST");
						assert(NULL);
					}
				}
				current_node = current_node->right;
			} else {
				return (cnt_tasks == tree->size);
			}
		}
	}
}
