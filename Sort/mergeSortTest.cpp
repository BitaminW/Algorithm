#include<iostream>

using namespace std;

int N, arr[1000001];
int* arr2;

void merge(int left, int right)
{	
	// (left + right) / 2 로 하게 될 경우 오버플로우 발생
	// 만약 left + right가 int의 범위를 벗어날 경우 문제가 생김
	int mid = left + ((right - left) / 2);

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];
	}

	int tmp = i > mid ? j : i;

	while (k <= right) arr2[k++] = arr[tmp++];

	for (int i = left; i <= right; i++) arr[i] = arr2[i];
}

void partition(int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

int main()
{
	scanf("%d", &N);
	arr2 = new int[N];
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	partition(0, N - 1);

	for (int i = 0; i < N; i++) printf("%d\n", arr[i]);
}
