#include <bits/stdc++.h>
using namespace std;

void countFreq(int arr[], int n)
{
    unordered_map<int, int> map(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    for (auto e : map)
    {
        cout << e.first << " " << e.second << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 2, 2, 2, 5, 6, 7, 8};
    int n = 9;
    countFreq(arr, n);
    return 0;
}