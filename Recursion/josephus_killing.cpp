#include <iostream>
using namespace std;

int joseph(int n, int k)
{
    //Base Case
    if (n == 1)
        return 0;

    //Recursive case
    return (joseph(n - 1, k) + k) % n;
}
int main()
{
    int n = 5;
    int k = 3;
    int ans = joseph(n, k);
    cout << ans;
    return 0;
}