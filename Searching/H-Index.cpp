#include <bits/stdc++.h>
using namespace std;
//Goldmann Sachs Online round
int hIndexHelper(vector<int> &citations)
{
    int n = citations.size();
    int low = 0, high = citations.size() - 1;

    while (low <= high)
    {
        int mid = low + high >> 1;
        if (citations[mid] == n - mid)
        {
            return n - mid;
        }
        else if (citations[mid] < n - mid)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return n - low;
}
int hIndex(vector<int> &citations)
{
    sort(citations.begin(), citations.end());
    return hIndexHelper(citations);
}
