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

//other way
class Solution {
public:
    int hIndex(vector<int>& citations) {
        unordered_map<int,int> mp;
        int n = citations.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(citations[i] >= n)mp[n]++;
            else mp[citations[i]]++;
        }
        
        int paper = 0;
        for(int i = n ; i >= 0 ; i--){
            paper += mp[i];
            if(paper >= i){
                return i;
            }
        }
        return 0;
    }
};
//O(n) time 
//O(n) space
