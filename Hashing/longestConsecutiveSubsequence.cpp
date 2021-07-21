
#include <bits/stdc++.h>
using namespace std;

int longestConsecSeq(int arr[], int n)
{
    //naive method
    // sort(arr, arr + n);
    // int len = 1;
    // int maxLen = 1;
    // for (int i = 1; i < n; i++)
    // {
    //     if (arr[i - 1] + 1 == arr[i])
    //     {
    //         len++;
    //     }
    //     else if (arr[i] != arr[i - 1])
    //     {
    //         maxLen = max(len, maxLen);
    //         len = 1;
    //     }
    // }
    // return max(maxLen, len);

    unordered_set<int> s;
    int len = 1;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    for (auto x : s)
    {
        if (s.find(x - 1) == s.end())
        {
            int curr = 1;
            while (s.find(x + curr) != s.end())
            {
                curr++;
            }
            len = max(len, curr);
        }
    }
    return len;
}

int main()
{
    int arr1[] = {1, 9, 3, 4, 2, 20};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout << longestConsecSeq(arr1, n);
    return 0;
}
