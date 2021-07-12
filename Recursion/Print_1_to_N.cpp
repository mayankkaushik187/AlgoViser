#include <iostream>
#include <vector>
using namespace std;

void print(int n)
{
    //base case
    if (n == 0)
    {
        return;
    }
    print(n - 1);
    cout << n << ' ';
}

int main()
{
    int n = 6;
    print(n);
    return 0;
}