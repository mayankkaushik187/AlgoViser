#include <bits/stdc++.h>
using namespace std;

void printPrevGreater(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    int prevg = -1;
    cout << "-1"
         << " ";
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        prevg = s.empty() ? -1 : s.top();
        cout << prevg << " ";
        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {20, 30, 10, 5, 15};
    int n = 5;
    printPrevGreater(arr, n);
    return 0;
}
