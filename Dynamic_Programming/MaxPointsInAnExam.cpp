#include <bits/stdc++.h>
using namespace std;

//Codechef Starters 12 problem ID- MAXPOINT
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> wt;
        vector<int> val;
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = 0; i < 20; i++)
        {

            wt.push_back(a);
            wt.push_back(b);
            wt.push_back(c);
        }
        int x, y, z;
        cin >> x >> y >> z;
        for (int i = 0; i < 20; i++)
        {
            val.push_back(x);
            val.push_back(y);
            val.push_back(z);
        }

        int W = 240;
        int n = 60;
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 0; i <= W; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (wt[i - 1] > j)
                {

                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
                }
            }
        }

        cout << dp[n][W] << endl;
    }
}
