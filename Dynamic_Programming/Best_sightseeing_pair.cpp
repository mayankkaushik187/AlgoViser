#include <bits/stdc++.h>
using namespace std;

int maxScoreSightseeingPair(vector<int> &values)
{
    int n = values.size();
    //8 1 5 2 6
    //0
    int sum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, values[i] + sum);
        sum = max(sum, values[i]) - 1;
    }

    return res;
}