#include <iostream>
#include <vector>
using namespace std;

int stockProfit(vector<int> &v, int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {

        if (v[i] > v[i - 1])
        {
            profit += v[i] - v[i - 1];
        }
    }
    return profit;
}
int main()
{
    vector<int> v = {1, 5, 7, 8, 9, 10, 2, 3};
    int n = v.size();
    cout << "The max profit is " << stockProfit(v, n);
    return 0;
}