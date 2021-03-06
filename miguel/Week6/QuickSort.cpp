// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;

void quickSort(int arr[], int left, int right) {
	int leftIdx = left, rightIdx = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (leftIdx <= rightIdx) {
		while (arr[leftIdx] < pivot)
			leftIdx++;

		while (arr[rightIdx] > pivot)
			rightIdx--;

		if (leftIdx <= rightIdx) {
			tmp = arr[leftIdx];
			arr[leftIdx] = arr[rightIdx];
			arr[rightIdx] = tmp;
			leftIdx++;
			rightIdx--;
		}
	};

	/* recursion */
	if (left < rightIdx)
		quickSort(arr, left, rightIdx);

	if (leftIdx < right)
		quickSort(arr, leftIdx, right);
}

int const NUM = 10;
int main() {
	int intArray[NUM];
	ofstream outfile1, outfile2;
	outfile1.open("unsorted.dat");
	outfile2.open("sorted.dat");

	//populate the array with random values
	for (int i = 0; i < NUM; ++i) {
		intArray[i] = 13 * rand() % NUM;
		outfile1 << i << ". " << intArray[i] << endl;
	}

	//sort the array with QuickSort
	double startTime, endTime, totalTime;
	startTime = GetTickCount();//milliseconds
	quickSort(intArray, 0, NUM-1);
	endTime = GetTickCount();//milliseconds
	totalTime = endTime - startTime;
	cout << "The sort of " << NUM << " entries took " << totalTime << " milliseconds." << endl;

	//display the results
	for (int i = 0; i < NUM; ++i) {
		outfile2 << i << ". " << intArray[i] << endl;
	}

	return 0;
}