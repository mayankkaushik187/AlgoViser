//Naive approach

int gcd(int a, int b)
{
    int min = min(a, b);
    int maxDivisor = INT_MIN;
    for (int i = 1; i <= min; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            if (maxDivisor < i)
            {
                maxDivisor = i;
            }
        }
    }
    return maxDivisor;
}

// Optimised Approach(Euclidian theorem)
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
//time complexity == > O(log(max(a,b)))
//Auxiliary space complexity == > O(1)