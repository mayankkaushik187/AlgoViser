int tZeros(int n)
{
    int res = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        res += n / i;
    }
    return res;
}

//time complexity == > Theta(log(n))
//Auxiliary space complexity == > Theta(1)