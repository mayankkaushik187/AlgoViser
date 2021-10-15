//Leetcode 347
static bool cmp(pair < int, int > & p1, pair < int, int > & p2) {
    return p1.second > p2.second;
}
vector < pair < int, int >> sortmap(map < int, int > & mp) {
    vector < pair < int, int >> helper;
    for (auto & x: mp) {
        helper.push_back(x);
    }
    sort(helper.begin(), helper.end(), cmp);
    return helper;
}
vector < int > topKFrequent(vector < int > & nums, int k) {
    map < int, int > mp;
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }

    auto ans = sortmap(mp);
    vector < int > res;
    for (int i = 0; i < ans.size() and res.size() < k; i++) {
        res.push_back(ans[i].first);
    }
    return res;
}
