#include <stdio.h>

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n ; i++)
		for (j = i+1; j < n ; j++)
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	int arr[] = { 5, 18 , 44 , 14 , 12 , 19  };
	int n = 6;
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
