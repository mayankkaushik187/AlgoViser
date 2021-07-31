#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int arr[], int n)
{
    int res = 0;
    int curr = 0;
    int tp = -1;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            tp = s.top();
            s.pop();
            curr = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            res = max(res, curr);
        }
        s.push(i);
    }
    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        curr = arr[tp] * (s.empty() ? n : n - s.top() - 1);
        res = max(res, curr);
    }
    return res;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    int n = 7;
    cout << "Maximum Area: " << getMaxArea(arr, n);
    return 0;
}