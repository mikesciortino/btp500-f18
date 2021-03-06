// RecursiveBinarySearch.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <windows.h>

int rBinarySearch(int sortedArray[], int first, int last, int key);

int iterations = 0;
int main()
{
	const int KEY_SIZE = 65535;//2^16-1, should take a maximum of 16 iterations to find the key
	int array[KEY_SIZE];
	int key;
	int index = -1;

	//Populate the array;
	for (int i = 0; i < KEY_SIZE; ++i) array[i] = i;

	//Get the key
	printf("We've got a sorted array of 0-%d.\nEnter the key you wish to find: ", KEY_SIZE-1);
	scanf("%d", &key);

    //Create new file
	FILE *fp = fopen("RecursiveBinarySearch.txt", "w");
	fclose(fp);

	//Perform recursive binary search
	index = rBinarySearch(array, 0, KEY_SIZE-1, key);

	printf("The key %d appears at index %d. It took %d iterations to find.\n", key, index, iterations);
	fp = fopen("RecursiveBinarySearch.txt", "a");
	fprintf(fp, "The key %d appears at index %d. It took %d iterations to find.\n", key, index, iterations);
	fclose(fp);
	Sleep(5000);

    return 0;
}

int rBinarySearch(int sortedArray[], int first, int last, int key) {
	// function:
	//   Searches sortedArray[first]..sortedArray[last] for key.  
	// returns: index of the matching element if it finds key, 
	//         otherwise  -(index where it could be inserted)-1.
	// parameters:
	//   sortedArray in  array of sorted (ascending) values.
	//   first, last in  lower and upper subscript bounds
	//   key         in  value to search for.
	// returns:
	//   index of key, or -insertion_position -1 
	//                 if key is not in the array.

	++iterations;//Keep track of the number of iterations
	printf("rBinarySearch(first:%d, last:%d, key:%d): iterations:%d\n", first, last, key, iterations);
	FILE *fp = fopen("RecursiveBinarySearch.txt", "a");
	fprintf(fp, "rBinarySearch(first:%d, last:%d, key:%d): iterations:%d\n", first, last, key, iterations);
	fclose(fp);
	Sleep(2000);
	if (first <= last) {
		int mid = (first + last) / 2;  // compute mid point.
		if (key == sortedArray[mid]) {
			printf("rBinarySearch(first:%d, last:%d, key:%d): return mid:%d\n", first, last, key, mid);
			fp = fopen("RecursiveBinarySearch.txt", "a");
			fprintf(fp, "rBinarySearch(first:%d, last:%d, key:%d): return mid:%d\n", first, last, key, mid);
			fclose(fp);
			Sleep(2000);
			return mid;   // found it.
		} else if (key < sortedArray[mid]) {
			// Call ourself for the lower part of the array
			return rBinarySearch(sortedArray, first, mid - 1, key);
		} else {
			// Call ourself for the upper part of the array
			return rBinarySearch(sortedArray, mid + 1, last, key);
		}
	}
	fp = fopen("RecursiveBinarySearch.txt", "a");
	fprintf(fp, "rBinarySearch(first:%d, last:%d, key:%d): return -1\n", first, last, key);
	fclose(fp);
	Sleep(2000);
	return -1;    // failed to find key
}

