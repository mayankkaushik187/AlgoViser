int countDigits(int x)
{
    if (x == 0)
    {
        return 0;
    }
    return 1 + countDigits(x / 10); // or alternatively *return floor(log10(n) + 1);*
}