#include "treenode.h"

// It is used to order 
// nodes of your tree. 
// This comparison function 
// should return -1,0 or 1 (like strcmp)
int comp (void* p1, void* p2) {
	 return *(int*)p1 == *(int*)p2;
}

int sum(int* a, int* b){
	return *a+*b;
}

int main(){
	int x,y;
	x = y = 5;
	int *px, *py;
	px = &x;
	py = &y;
	
	printf("%p\n", px);

	int z = sum(px, py);

	z = comp((void*)px, (void*)py);

	printf("%d\n", z);
}