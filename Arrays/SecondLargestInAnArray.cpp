#include <iostream>
#include <vector>
using namespace std;

int LargestInAnArray(vector<int> &v, int n)
{
    int n = v.size();
    int maxIndex = 0;
    int secMaxIndex = 0;
    for (int i = 1; i < n; i++) // find the maxIndex
    {
        if (v[i] > v[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int secondLargest(vector<int> &v, int n)
{

    int largest = LargestInAnArray(v, n);
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != v[largest])
        {
            if (res == -1)
            {
                res = i;
            }
            else if (v[i] > v[res])
            {
                res = i;
            }
        }
    }
    return res;
} // O(n)
//=================================X==================================
// Efficient Approach

int secondLargest(vector<int> &v, int n) //O(n)
{
    int res = -1;
    int largest = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] > v[largest])
        {
            res = largest;
            largest = i;
        }
        else if (v[i] < v[largest])
        {
            if (res == -1)
            {
                res = i;
            }
            else if (v[i] > v[res])
            {
                res = i;
            }
        }
    }
    return res;
}

//10 4 7 6 3 6