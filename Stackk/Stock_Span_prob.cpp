#include <bits/stdc++.h>
using namespace std;

void printSpan(int arr[], int n)
{

    stack<int> s;
    vector<int> res;
    int span = 1;
    s.push(0);
    cout << 1 << " ";

    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        span = s.empty() ? i + 1 : i - s.top();
        cout << span << " ";
        s.push(i);
    }
}

int main()
{
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = 7;
    printSpan(arr, n);
    return 0;
}