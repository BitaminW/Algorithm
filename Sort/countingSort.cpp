#include <bits/stdc++.h>
#include <string.h>

#define ARRLEN 11
#define RANGE 255

using namespace std;

void countSort(char arr[]) {
	
	char output[ARRLEN];

	int count[RANGE + 1];
	memset(count, 0, sizeof(count));

	for (int i = 0; i < arr[i]; ++i)
		++count[arr[i]];

	for (int i = 1; i <= RANGE; ++i)
		count[i] += count[i - 1];

	for (int i = 0; arr[i]; ++i) {
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}

	for (int i = 0; arr[i]; ++i)
		arr[i] = output[i];

}

int main() {
	
	char arr[] = "helloworld";

	countSort(arr);

	cout << "결과 값: " << arr;

	return 0;
}

