#include <iostream>
#include <vector>
using namespace std;

int power(int x, int n)
{
    int res = 1;
    while (n > 0)
    {
        res *= x;
        n--;
    }
    return res;
}
//time complexity ===> O(n) , n being the power for which we need to calculate

//O(log n) approach
int power(int x, int n)
{
    int res = 1;

    while (n > 0)
    {
        if (n & 1)
        { // same as (n%2 != 0)
            res = res * x;
        }
        x = x * x;
        n = n >> 1;
    }
    return res;
}