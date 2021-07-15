#include <bits/stdc++.h>
using namespace std;

int MajorityElement(int a[], int n)
{
    int count = 1;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[res] == a[i])
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[res] == a[i])
        {
            count++;
        }
    }
    if (count <= n / 2)
    {
        res = -1;
    }
    return res;
}

int main()
{

    int a1[] = {10, 20, 30, 40, 50}, n1 = 5;

    cout << MajorityElement(a1, n1);

    return 0;
}