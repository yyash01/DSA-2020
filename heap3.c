/*
concept of (HEAPYFY-down)

Heapify down is used when we remove the top element from a heap.
Removal of an element is done by swapping the top element with the last element at the bottom of the tree,
removing the last element, and then heapfying the new top element down to maintain the heap property.
Because this moves down the heap tree, it must perform two comparisons per iteration, with the left child and the right child elements,
then swap with the smaller one.
Because of this, heapify down is usually more complex to implement than heapify up.

*/

#include<stdio.h>
#include<stdlib.h>

HEAP_SIZE = 30;

struct heap {
	int *arr;
	int count;
	int capacity;
	int heap_type;  //(1 for max heap) and (0 for min heap)
};
typedef struct heap wtf;
int sorted[30] = {0};
wtf *CreateHeap(int capacity, int heap_type)
{
	wtf *h = (wtf *)malloc(sizeof(wtf));

	//check the memory allocation
	if (h == NULL) {
		printf("memory error!");
		return;
	}
	h->heap_type = heap_type;
	h->count = 0;
	h->capacity = capacity;

	//allocating memory to store in the array .
	//the memory is allocated for only capacity of heap;
	h->arr = (int *)malloc(capacity * sizeof(int));

	//check if memory allocation works or not
	if (h->arr == NULL) {
		printf("memory error !");
		return;
	}
	return h;
}

void heapify_up(wtf *h, int index) //making of min heap
{
	int parent = (index - 1) / 2;
	int temp;

	//min heap condition
	//parent node is less than the both child node
	if (h->arr[parent] > h->arr[index]) {
		//swap them
		temp = h->arr[parent];
		h->arr[parent] = h->arr[index];
		h->arr[index] = temp;
		//making recursive call for all other
		heapify_up(h, parent); //parent ka bhi parent ho skta hai na
	}
}
void insert(wtf *h, int key) {
	if (h->count < h->capacity) {
		h->arr[h->count] = key;
		heapify_up(h, h->count);
		(h->count)++;
	}
}

void heapify_down(wtf *h, int parent)
{
	int left = 2 * parent + 1;
	int right = 2 * parent + 2;
	int min;
	int temp;
	if (left > h->count || left < 0)
		left = -1;
	if (right > h->count || right < 0)
		right = -1;

	if (left != -1 && h ->arr[left] < h->arr[parent]) {
		min = left;
	}
	else
		min = parent;
	if (right != -1 && h->arr[right] < h->arr[parent]) {
		min = right;
	}

	if (min != parent) {
		temp = h->arr[min];
		h->arr[min] = h ->arr[parent];
		h->arr[parent] = temp;
	}

	//recusive call
	heapify_down(h, min);
}

int pop_min(wtf*h)
{
	int pop;
	if (h->count == 0) {
		printf("\n__HEAP IS EMPTY___");
		return -1;
	}
	pop = h->arr[0];
	h->arr[0] = h->arr[h->count - 1];
	h->count--;
	heapify_down(h, 0);
	return pop;
}




//function to print a heap
void print(wtf *h)
{
	int i;
	printf("________printing-Heap_________\n");
	for (i = 0; i < h->count; i++) {
		printf("%d ", h->arr[i]);
	}
	printf("\n__//\\___\n");
}



int main()
{
	int i;
	wtf *heap = CreateHeap(HEAP_SIZE, 0);
	if (heap == NULL) {
		printf("Memory error____\n");
		return -1;
	}
	for (i = 13; i > 0; i--) {
		insert(heap, i);
	}

	print(heap);
	int j = 0;
	for (i = 13; i > 0; i--) {
		sorted[j++] = pop_min(heap);
		printf("Pop Minima : %d\n", pop_min(heap));
		print(heap);
	}
	for (int i = 0; i <= j; i++) {
		printf("\n__SORTED _ARRAY_ __\n");
		printf("%d ", sorted[i]);
	}

	return 0;
}
