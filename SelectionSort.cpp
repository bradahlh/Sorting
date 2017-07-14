#include <iostream>
using namespace std;

void SelectionSort(int array[], int size);

int main()
{
	int list[] = { 5,3,1,4 };				// Initialize array
	int listSize = sizeof(list)/sizeof(int);// Compute # of elements
	
	// Displays array before sort
	cout << "Array before sort:" << endl;
	for (int i = 0; i < listSize; i++)
		cout << list[i] << " ";

	SelectionSort(list, listSize);
	// Displays array after sort
	cout << "\nArray after sort:" << endl;
	for (int j = 0; j < listSize; j++)
		cout << list[j] << " ";

	cout << endl << endl;
	return 0;
}

void SelectionSort(int array[], int size)
{
	for (int i = 0; i < size-1; i++)		// Runs from idx 0 to 2nd last
	{
		int small = i;						// Presumes index i to be smallest
		for (int j = i + 1; j < size; j++)	// Checks against idx <next> to last
			if (array[j] < array[small])
				small = j;					// Sets new smallest (if found)
		int temp = array[i];				// Swaps smallest with elmnt at
		array[i] = array[small];			//   current idx
		array[small] = temp;
	}
}