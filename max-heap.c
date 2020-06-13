#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int parent(int i)
{
	return (i - 1) / 2;
}
int left(int i) {
	return 2 * i + 1;
}
int right(int i) {
	return 2 * i + 2;
}
void maxheapify(int arr[], int n, int i)
{
	int l, r, large, temp;
	l = left(i);
	r = right(i);
	if (l < n && arr[l] > arr[i])
		large = l;
	else
		large = i;
	if (r < n && arr[r] > arr[large])
		large = r;
	//taking largest to the root node
	if (large != i) {
		temp = arr[i];
		arr[i] = arr[large];
		arr[large] = temp;
		//recursively heapify the affected sub-tree
		maxheapify(arr, n, large);
	}

}
void main()
{
	int arr[20];
	int i = 0, n;
	printf("Enter the Number of Elements in array: ");
	scanf("%d", &n);
	printf("\nEnter the Elements :");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	printf("\nArray before max heap\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d", arr[i]);
	}
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		maxheapify(arr, n, i);
	}
	printf("\nArray after Max-Heap\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
	}
}
