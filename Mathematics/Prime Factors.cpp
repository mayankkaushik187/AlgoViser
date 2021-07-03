#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//O(sqrt(n))
int primefactors(int n)
{
    if (n <= 1)
    {
        return;
    }
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1)
    {
        cout << n;
    }
}

//More efficient
//this approach minimizes the no. of iterations drastically for larger values of n
int primefactors(int n)
{
    if (n <= 1)
    {
        return;
    }
    while (n % 2 == 0)
    {
        cout << 2;
        n = n / 2;
    }
    while (n % 3 == 0)
    {
        cout << 3;
        n = n / 3;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
        while (n % (i + 2) == 0)
        {
            cout << i + 2 << " ";
            n /= i + 2;
        }
    }
    if (n > 1)
    {
        cout << n;
    }
}