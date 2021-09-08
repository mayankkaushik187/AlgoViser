#include <bits/stdc++.h>
using namespace std;
int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    //Write your code here
    vector<vector<int>> dp(value + 1, vector<int>(numDenominations, 0));
    for (int i = 0; i < numDenominations; i++)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= value; i++)
    {
        for (int j = 0; j < numDenominations; j++)
        {
            int x = (i - denominations[j] >= 0) ? dp[i - denominations[j]][j] : 0;

            int y = (j >= 1) ? dp[i][j - 1] : 0;

            dp[i][j] = x + y;
        }
    }
    return dp[value][numDenominations - 1];
}

int main()
{

    int numDenominations;
    cin >> numDenominations;

    int *denominations = new int[numDenominations];

    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }

    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);

    delete[] denominations;
}