#include <bits/stdc++.h>

using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> sum = {0}, posL(n, 0), posR(n, n - k);

    //compute the sum array;

    for (int i = 0; i < n; i++)
    {
        sum.push_back(sum.back() + nums[i]);
    }

    //build posL array;
    for (int i = k, tot = sum[k] - sum[0]; i < n; i++)
    {
        if (sum[i + 1] - sum[i + 1 - k] > tot)
        {
            tot = sum[i + 1] - sum[i + 1 - k];
            posL[i] = i + 1 - k;
        }
        else
            posL[i] = posL[i - 1];
    }

    //build posR array;
    for (int i = n - k - 1, tot = sum[n] - sum[n - k]; i >= 0; i--)
    {
        if (sum[i + k] - sum[i] >= tot)
        {
            tot = sum[i + k] - sum[i];
            posR[i] = i;
        }
        else
            posR[i] = posR[i + 1];
    }
    int maxSum = 0;
    vector<int> ans(3, -1);
    for (int i = k; i <= n - 2 * k; i++)
    {
        int l = posL[i - 1], r = posR[i + k];
        int tot = sum[i + k] - sum[i] + sum[l + k] - sum[l] + sum[r + k] - sum[r];
        if (tot > maxSum)
        {
            maxSum = tot;
            ans = {l, i, r};
        }
    }

    return ans;
}