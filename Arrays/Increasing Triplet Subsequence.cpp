//Leetcode 334

bool increasingTriplet(vector < int > & nums) {
    if (nums.size() < 3) return false;

    int small = INT_MAX;
    int big = INT_MAX;
    for (auto x: nums) {
        if (x <= small) small = x;
        else if (x <= big) big = x;
        else return true;
    }

    return false;
}
