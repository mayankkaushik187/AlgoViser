bool isPal(int n)
{
    int temp = n;
    int rev = 0;
    while (temp != 0)
    {
        rev = rev * 10 + rev % 10;
        temp /= 10;
    }
    return (rev == n);

    //time complextiy ---> Theta(d) where d is the no. of digits in our number n
}