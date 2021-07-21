
#include <bits/stdc++.h>
using namespace std;

int longestConsecSeq(int arr[], int n)
{

    sort(arr, arr + n);
    int len = 1;
    int maxLen = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] + 1 == arr[i])
        {
            len++;
        }
        else if (arr[i] != arr[i - 1])
        {
            maxLen = max(len, maxLen);
            len = 1;
        }
    }
    return max(maxLen, len);
}

int main()
{
    int arr1[] = {1, 9, 3, 4, 2, 20};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout << longestConsecSeq(arr1, n);
    return 0;
}
