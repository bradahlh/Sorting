#include <iostream>
using namespace std;

void Quicksort(int a[], int left, int right);
void Swap(int a[], int indxOne, int indxTwo);

int main()
{
	int arr[] = { -999,2,6,4,5,1 };		// Index 0 is sentinel key
	int arrSize = sizeof(arr) / sizeof(int);

	cout << "Array before sort:" << endl;
	for (int i = 1; i < arrSize; i++)
		cout << arr[i] << " ";

	Quicksort(arr, 1, arrSize-1);		// Sort without sentinel key
	cout << "\n\nArray after sort:" << endl;
	for (int i = 1; i < arrSize; i++)
		cout << arr[i] << " ";

	cout << endl << endl;
	return 0;
}

void Quicksort(int a[], int left, int right)
{
	int leftScan,	// Left scan pointer
		rightScan,	// Right scan pointer
		pivot;		// Pivot element

	if (right > left)			// More than one element in (sub) array
	{
		pivot = a[right];		// Lets rightmost key be pivot
		leftScan = left - 1;	// Left scan index starts "out of bounds"
		rightScan = right;		// Right scan index starts at rightmost item

		for (;;)				// Infinite loop until right and left scan ptrs cross
		{
			while (a[++leftScan] < pivot);	// Left scan increments to check for keys greater than pivot
			while (a[--rightScan] > pivot);	// Right scan decrements to check for keys lesser than pivot
			if (leftScan >= rightScan)		// Break if scan pointers have crossed
				break;						
			Swap(a, leftScan, rightScan);	// Swap keys if scan pointers haven't crossed
		}
		Swap(a, leftScan, right);			// Swaps pivot with rightmost element greater than pivot (pivot key is now in its final place)
		Quicksort(a, left, leftScan - 1);	// Recursively sorts left sub array
		Quicksort(a, leftScan + 1, right);	// Recursively sorts right sub array
	}
}

// Swaps to keys
void Swap(int a[], int indxOne, int indxTwo)
{
	int temp = a[indxOne];
	a[indxOne] = a[indxTwo];
	a[indxTwo] = temp;
}