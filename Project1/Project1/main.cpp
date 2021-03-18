#include <iostream>

using namespace std;

//p is the index of the first element in aArray, i.e. starting index of array
//r is the index of the last element in aArray, i.e. ending index of array
void quickSort (int aArray[], int p, int r);
int partition (int aArray[], int p, int r);

int main ()
{
	const int SIZE = 8;
	int numArray[SIZE] = {5, 3, 9, 1, 8, 2, 4, 7};
	cout << "UNSORTED: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << numArray[i] << " ";
	}
	cout << endl;
	quickSort (numArray, 0, SIZE - 1);
	cout << "QUICK SORT: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << numArray[i] << " ";
	}
	cout << endl;
	return EXIT_SUCCESS;
}void quickSort (int aArray[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition (aArray, p, r);
		quickSort (aArray, p, q - 1); //everything to the left of the pivot
		quickSort (aArray, q + 1, r); //everything to the right of the pivot
	}
}

int partition (int aArray[], int p, int r)
{
	int temp;
	int pivot = aArray[r];
	int i = p - 1;

	for (int j = p; j < pivot; j++) 
	{
		if (aArray[j] <= pivot) 
		{
			i++;
			//swap aArray[i] and aArray[j]
			temp = aArray[j];
			aArray[j] = aArray[i];
			aArray[i] = temp;
		}
	}

	//swap aArray[i+1] and aArray[r]
	temp = aArray[r];
	aArray[r] = aArray[i + 1];
	aArray[i + 1] = temp;
	return i + 1;
}
