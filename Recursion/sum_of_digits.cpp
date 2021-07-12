#include <iostream>
#include <vector>
using namespace std;

int sumDigits(int n)
{
    //base case
    if (n / 10 == 0)
    {
        return n % 10;
    }

    //recursive case
    return (n % 10) + sumDigits(n / 10);
}

int main()
{
    int n = 12345;

    cout << sumDigits(n);
    return 0;
}