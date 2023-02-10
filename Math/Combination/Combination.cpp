#include <iostream>
using namespace std;

int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int cnt, n, r;
int order[4];

void combination(int now, int pos)
{
	if (now == r)
	{
		for (int i = 0; i < r; i++)
		{
			cout << arr[order[i]] << " ";
		}
		cout << endl;
		cnt++;

		return;
	}

	for (int idx = pos; idx < n; idx++)
	{
		order[now] = idx;
		combination(now + 1, idx + 1);
	}
}

int main()
{
	cout << "n : ";
	cin >> n;
	cout << "r : ";
	cin >> r;
	cout << n << 'C' << r << endl;

	combination(0, 0);
	cout << "조합의 개수 : " << cnt;
}
