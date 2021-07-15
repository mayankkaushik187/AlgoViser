#include <bits/stdc++.h>
using namespace std;

int RepeatElement(int a[], int n)
{
    vector<bool> visited(n - 1, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[a[i]])
        {
            return a[i];
        }
        visited[a[i]] = true;
    }
    return -1; // For no repeating element
}

int main()
{
    int a1[] = {0, 2, 3, 2, 2, 4, 6}, n1 = 7;

    cout << RepeatElement(a1, n1);

    return 0;
}
