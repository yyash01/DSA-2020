/*
concept of (HEAPYFY -up)


Heapify up is used when we insert a new element to a heap.
When inserting a new element, we add it at the bottom of the heap tree,
and move up the tree while comparing to the current parent element and swapping if needed.
Because we move up for heapify up, we only make one comparison per iteration,
between the current element and its parent element.
*/
/*
concept of (HEAPYFY-down)

Heapify down is used when we remove the top element from a heap.
Removal of an element is done by swapping the top element with the last element at the bottom of the tree,
removing the last element, and then heapfying the new top element down to maintain the heap property.
Because this moves down the heap tree, it must perform two comparisons per iteration, with the left child and the right child elements,
then swap with the smaller one.
Because of this, heapify down is usually more complex to implement than heapify up.

*/

//---------------------------------CREATING MIN-HEAP----------------------------------------------------------------//
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

//function to print a heap
void print(wtf *h)
{
	int i;
	printf("________printing-Heap_________\n");
	for (i = 0; i < h->count; i++) {
		printf("%d ", h->arr[i]);
	}
	printf("\n__/\\___");
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

	return 0;
}
