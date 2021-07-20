#include <bits/stdc++.h>
using namespace std;

int intersection(int arr1[], int m, int arr2[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.find(arr2[i]) != s.end())
        {
            res++;
            s.erase(arr2[i]);
        }
    }

    for (auto e : s)
    {
        cout << e << " " << endl;
    }

    return res;
}
//returns number of intersecting elements in both the arrays

int main()
{
    int arr1[] = {15, 17, 27, 27, 28, 15};
    int arr2[] = {16, 17, 28, 17, 31, 17};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    cout << intersection(arr1, m, arr2, n);

    return 0;
}