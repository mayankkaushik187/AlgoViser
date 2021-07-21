#include <bits/stdc++.h>
using namespace std;

vector<int> countDist(int arr[], int n, int k)
{
    unordered_map<int, int> freq;
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        freq[arr[i]]++;
    }
    res.push_back((int)freq.size());

    for (int i = k; i < n; i++)
    {
        freq[arr[i - k]]--;
        if (freq[arr[i - k]] == 0)
        {
            freq.erase(arr[i - k]);
        }
        freq[arr[i]]++;
        res.push_back((int)freq.size());
    }
    return res;
}

int main()
{
    int arr1[] = {10, 10, 5, 3, 20, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int k = 4;
    vector<int> res = countDist(arr1, n, k);
    for (int x : res)
    {
        cout << x << " ";
    }
    return 0;
}
