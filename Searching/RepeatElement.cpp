#include <bits/stdc++.h>
using namespace std;

int RepeatElement(int a[], int n) //O(n) time and space
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

int RepeatElementEff(int a[], int n) //O(n) time and O(1)space
{
    int slow = a[0];
    int fast = a[0];
    do
    {
        slow = a[slow];
        fast = a[a[fast]];
    } while (slow != fast);

    slow = a[0];
    while (slow != fast)
    {
        slow = a[slow];
        fast = a[fast];
    }
    return slow;
}

int main()
{
    int a1[] = {1, 2, 3, 2, 5, 4, 6}, n1 = 7;

    cout << RepeatElementEff(a1, n1);

    return 0;
}
