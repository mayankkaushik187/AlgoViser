#include <iostream>
#include <vector>
using namespace std;

int isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    while (n == 2 || n == 3)
    {
        return true;
    }
    while (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        while (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
void SOE(int n) // time complexity ==> O(n^1.5)
{
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
}

//O(nloglogn) approach===>Time Complexity
//O(n)===>Auxiliary Space
int soe(int n)
{
    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}