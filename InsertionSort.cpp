#include <iostream>
using namespace std;

void InsertionSort(int a[], int n);

int main()
{
	int arr[] = { 0,4,3,2,5,6,3,1,10,23,2,5,3,8 };
	int size = sizeof(arr) / sizeof(int);	// Compute # of elements

	// Display array before sorting
	cout << "Array before sort:\n";
	for (int i = 1; i < size; i++)
		cout << arr[i] << " ";

	InsertionSort(arr, size);

	// Display array after sorting
	cout << "\n\nArray after sort:\n";
	for (int i = 1; i < size; i++)
		cout << arr[i] << " ";

	cout << endl << endl;
	return 0;
}

void InsertionSort(int a[], int n)
{
	a[0] = -999999999;			// Avoids array going out of bounds
	for (int i = 2; i < n; i++)	// From second to last element
	{
		int temp = a[i];		// Stores current key for later
		int j = i;				// Var. for checking previous elements
		while (temp < a[j - 1])	// As long as current is smaller than previous
		{
			a[j] = a[j-1];		// Shift previous element right
			j--;				// Decr. to check more indexes
		}
		a[j] = temp;			// Put current key in "vacant" space
	}
}