int countDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return 1 + countDigits(n / 10); // or alternatively *return floor(log10(n) + 1);*
}