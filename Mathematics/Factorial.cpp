//iterative approach
int factorial(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
//time complexity == > Theta(n)
//Auxiliary space complexity == > Theta(1)

//Recursive approach
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

//time complexity == > Theta(n)
//Auxiliary space complexity == > Theta(n)