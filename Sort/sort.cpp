
#include <iostream>
#include <limits>
#define  MAX_SIZE   10

using namespace std;

void bubble_sort(int* arr, int arr_len) {
	int temp;

	for (int i = arr_len - 1; i > 0; i--) {
		bool flag = false;
		
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}
		// swap이 한번도 안 일어났을 경우 정렬 종료
		if (flag == false) break;
	}
}

void selection_sort(int *arr, int arr_len) {
	int min = 0, max = 0, temp = 0, index = 0;
	
	for (int i = 0; i < arr_len; i++) {
		min = 9999;
		
		for (int j = i; j < arr_len; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}

void insertion_sort(int* arr, int arr_len) {
	int temp, j;

	for (int i = 1; i < arr_len; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > temp) arr[j + 1] = arr[j];
			else break;
		}
		arr[j + 1] = temp;
	}
}


void merge(int arr[],const int left,const int mid,const int right) {
	
	const auto subArrayOne = mid - left + 1;
	const auto subArrayTwo = right - mid;

	auto* leftArray  = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	for(auto i = 0; i < subArrayOne; i++) {
		leftArray[i] = arr[left + i];
	}
	for (auto j = 0; j < subArrayTwo; j++) {
		rightArray[j] = arr[mid + 1 + j];
	}
	
	auto indexOfSubArrayOne = 0,
		 indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		arr[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	
	while (indexOfSubArrayTwo < subArrayTwo) {
		arr[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;

}

void merge_sort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	merge_sort(array, begin, mid);
	merge_sort(array, mid + 1, end);
	merge(array, begin, mid, end);
}
