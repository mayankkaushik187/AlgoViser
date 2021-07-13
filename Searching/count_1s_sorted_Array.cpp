#include <iostream>
#include <vector>
using namespace std;

//Given a sorted Binary array find the count of 1's
int count_ones(vector<int> &a, int n)
{
    int index = 0;
    for (int i = 0; i < n; i++)
    {

        if (a[i] == 1)
        {
            index = i;
            break;
        }
    }
    return n - index;
}

int main()
{
    vector<int> arr = {0, 0, 0, 0, 1, 1, 1, 1, 1};
    int n = arr.size();

    cout << count_ones(arr, n);

    return 0;
}