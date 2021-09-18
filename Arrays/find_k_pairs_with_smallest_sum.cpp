#include <bits/stdc++.h>
using namespace std;

//LEETCODE 373
vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<vector<int>> res;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    set<pair<int, int>> s;

    pq.push(make_pair(nums1[0] + nums2[0], make_pair(0, 0)));
    s.insert(make_pair(0, 0));

    bool flag = true;

    for (int pairs = 0; pairs < k && flag; pairs++)
    {
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();

        int i = temp.second.first;
        int j = temp.second.second;

        res.push_back({nums1[i], nums2[j]});

        flag = false;

        if (i + 1 < nums1.size())
        {
            int sum = nums1[i + 1] + nums2[j];
            pair<int, int> temp1 = make_pair(i + 1, j);

            if (s.find(temp1) == s.end())
            {
                pq.push(make_pair(sum, temp1));
                s.insert(temp1);
            }
            flag = true;
        }

        if (j + 1 < nums2.size())
        {
            int sum = nums1[i] + nums2[j + 1];
            pair<int, int> temp1 = make_pair(i, j + 1);

            if (s.find(temp1) == s.end())
            {
                pq.push(make_pair(sum, temp1));
                s.insert(temp1);
            }
            flag = true;
        }
    }

    return res;
}