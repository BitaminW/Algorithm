
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
