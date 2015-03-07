#ifndef TREENODE_H
#define TREENODE_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int(*comp_fn)(void*, void*);
typedef void(*clean_fn)(void*);
typedef void(*print_fn)(void*);

typedef struct TreeNodeName {
    void *value;
    struct TreeNodeName *left;
    struct TreeNodeName *right;
    int cnt_dublicates;
} TreeNode;

typedef struct {
    TreeNode *base;
    comp_fn comp;
    clean_fn clean;
    print_fn print;
    int size;
} TreeBase;

typedef struct NodeList {
    TreeNode *tree_node;
    struct NodeList *next;
} StackNode;

int comp_ints (void* p1, void* p2);
void clean_ints(void* p);
void print_ints(void *p);

// Construct a new tree (which takes a comparison, print and clean method)
TreeBase* new_base(comp_fn co, clean_fn cl, print_fn p);
TreeNode* new_node(void* value, TreeNode *p_left, TreeNode *p_right);
// Look a value up in the tree - return NULL when comp finds no node equal to 'value'
TreeNode* query(TreeBase* tree, void* value);

// Add a value to the tree (this assumes the value is not already present).
bool insert(TreeBase* tree, void* data);

// Print a tree (from smallest to largest member, using the print function). 
bool printTree(TreeBase* tree);
// For debug purposes
void printNode(TreeNode* node);
// Free all memory from a tree (using the 'clean' function on each 'value')
bool freeTree(TreeBase* tree);

void push(StackNode **top_ref, TreeNode *t);
TreeNode *pop(StackNode **top_ref);
#endif