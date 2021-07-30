#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(int arr[], int n)
{
    vector<int> res;
    stack<int> s;
    s.push(arr[n - 1]);
    res.push_back(-1);

    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        int ng = s.empty() ? -1 : s.top();
        res.push_back(ng);
        s.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int arr[] = {5, 15, 10, 8, 6, 12, 9, 18};
    int n = 8;
    for (int x : nextGreater(arr, n))
    {
        cout << x << " ";
    }
    return 0;
}