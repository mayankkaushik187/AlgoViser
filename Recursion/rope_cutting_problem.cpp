#include <iostream>
#include <vector>
using namespace std;

int maxPieces(int n, int a, int b, int c)
{
    //base case
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;

    int res = max(maxPieces(n - a, a, b, c), (maxPieces(n - b, a, b, c), maxPieces(n - c, a, b, c)));
    if (res == -1)
    {
        return -1;
    }
    return 1 + res;
}

int main()
{
    int n = 23;
    int a = 11, b = 9, c = 12;
    int ans = maxPieces(n, a, b, c);
    cout << ans << endl;
    return 0;
}