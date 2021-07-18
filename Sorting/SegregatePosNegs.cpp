#include <bits/stdc++.h>
using namespace std;

void segPosNeg(int arr[], int n)
{
    int low = -1;
    int high = n;
    while (true)
    {
        do
        {
            low++;
        } while (arr[low] < 0);
        do
        {
            high--;

        } while (arr[high] >= 0);
        if (low >= high)
        {
            return;
        }
        swap(arr[low], arr[high]);
    }
}

int main()
{
    int arr[] = {-12, 18, -10, 15};
    int n = 4;
    segPosNeg(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}