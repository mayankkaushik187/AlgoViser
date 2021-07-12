#include <iostream>
#include <vector>
using namespace std;

int sumn(int n)
{
    //base case 5->4->3->2->1
    if (n == 0)
        return 0;

    return n + sumn(n - 1);
}
int main()
{
    int n = 5;
    cout << sumn(n);
}