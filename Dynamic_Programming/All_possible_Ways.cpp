/*
Given two integers a and b. You need to find and 
return the count of possible ways in which we can represent 
the number a as the sum of unique integers raise to the power b.
*/

#include <bits/stdc++.h>
//ez
int allWays(int x, int n, int curr_num = 1, int curr_sum = 0)
{
    int results = 0;
    // Calling power of 'i' raised to 'n'
    int p = pow(curr_num, n);
    while (p + curr_sum < x)
    {
        // Recursively check all greater values of i
        results += allWays(x, n, curr_num + 1, p + curr_sum);
        curr_num++;
        p = pow(curr_num, n);
    }
    // If sum of powers is equal to x
    // then increase the value of result.
    if (p + curr_sum == x)
        results++;
    // Return the final result
    return results;
}
int getAllWays(int a, int b)
{
    // Write your code here
    return allWays(a, b, 1, 0);
}
