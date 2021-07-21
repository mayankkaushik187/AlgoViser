#include <bits/stdc++.h>
using namespace std;

void printNByK(int arr[], int n, int k)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (auto x : freq)
    {
        if (x.second > (n / k))
        {
            cout << x.first << " ";
        }
    }
}

int main()
{
    int arr[] = {10, 10, 20, 30, 20, 10, 10};

    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    printNByK(arr, n, k);
}