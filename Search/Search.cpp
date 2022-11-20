#include <iostream>
using namespace std;
 
// 선형 탐색
int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}


// 재귀 탐색
int linearsearch(int arr[], int size, int key)
{
    if (size == 0) {
        return -1;
    }
    else if (arr[size - 1] == key) {
        // Return the index of found key.
        return size - 1;
    }
    else {
        int ans = linearsearch(arr, size - 1, key);
        return ans;
    }
}
 
 
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    int result = search(arr, N, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}
