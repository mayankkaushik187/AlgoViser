#include <bits/stdc++.h>
using namespace std;
//O(n) space and time;
void pushZerosToEnd(int arr[], int n)
{
    // code here
    stack<int> s;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        return;
    }
    for (int i = n - 1; i >= index; i--)
    {
        if (arr[i] != 0)
        {
            s.push(i);
        }
    }
    int i = 0;
    while (!s.empty())
    {
        if (arr[i] == 0)
        {
            swap(arr[i++], arr[s.top()]);
            s.pop();
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 2, 0, 4, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    pushZerosToEnd(arr, n);

    for (auto x : arr)
    {
        cout << x << " ";
    }
}