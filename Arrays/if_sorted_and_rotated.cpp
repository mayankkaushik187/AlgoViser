int minEle = INT_MAX;
int maxEle = INT_MIN;

int minIndex = -1;

for (int i = 0; i < n; i++)
{ // This will check for minimum element and its index!!!
    if (arr[i] < minEle)
    {
        minEle = arr[i];
        minIndex = i;
    }
}

int flag1 = 1;

//Check if all elements before minIndex are sorted
for (int i = 1; i < minIndex; i++)
{
    if (arr[i] < arr[i - 1])
    {
        flag1 = 0;
        break;
    }
}

int flag2 = 1;

//Check if all elements after minIndex are sorted

for (int i = minIndex + 1; i < n; i++)
{
    if (arr[i] < arr[i - 1])
    {
        flag2 = 0;
        break;
    }
}

if (flag1 && flag2 && (arr[n - 1] < arr[0]))
{
    return true;
}
else
{
    return false;
}