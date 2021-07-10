void rearrange(long long *arr, int n)
{

    // Your code here
    int maxIndex = n - 1;
    int minIndex = 0;
    int maxElement = arr[maxIndex] + 1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] += (arr[maxIndex] % maxElement) * maxElement;
            maxIndex--;
        }
        else
        {
            arr[i] += (arr[minIndex] % maxElement) * maxElement;
            minIndex++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] /= maxElement;
    }
}