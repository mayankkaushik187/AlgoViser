#include <bits/stdc++.h>
using namespace std;

int binarySearchHelper(int input[], int low, int high, int x)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + high >> 1;
    if (input[mid] < x)
    {
        return binarySearchHelper(input, mid + 1, high, x);
    }
    else if (input[mid] > x)
    {
        return binarySearchHelper(input, low, mid - 1, x);
    }
    else
    {
        return mid;
    }
}

int binarySearch(int input[], int size, int element)
{
    // Write your code here
    int low = 0;
    int high = size - 1;
    return binarySearchHelper(input, low, high, element);
}
