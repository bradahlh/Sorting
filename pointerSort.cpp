#include <iostream>
using namespace std;

void Insertion(int a[], int p[], int N);

int main() {
	int arr[] = { 4,32,2,54,23,2,64,99,2,4,5 };
	int sizeOfArray = sizeof(arr) / sizeof(int);

	return 0;
}

void Insertion(int a[], int p[], int N) {
	int i,
		j,
		temp;

	// Initializes array of pointers to 1, 2, 3,..., N
	for (i = 0; i < N; i++)
		p[i] = i;
	// Sorts array using the pointers
	for (i = 2; i < N; i++)
	{
		temp = p[i];				// temp stores index to be compared
		j = i;						// j stores original index
		while (a[p[j-1]] > a[temp])	// Preceding key(s) greater than current key
		{
			p[j] = p[j - 1];		// Shift array pointers right
			j--;					// Decreases j to compare with next preceding key
		}
		p[j] = temp;				// Inserts current key at right place
	}
}