class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;//maxheap
        
        int maxm = INT_MIN;
        int minm = INT_MAX;
        for(int i = 0 ; i < int(nums.size()) ; i++){
            nums[i] = nums[i] & 1 ? nums[i] * 2 : nums[i];
            maxm = max(maxm,nums[i]);
            minm = min(minm,nums[i]);
            pq.push(nums[i]);
        }
        //priority queue contains the elements after we have turned the odd ones into even
        int ans = maxm - minm;
        while(pq.top() % 2 == 0){
            auto front = pq.top();
            pq.pop();
            ans = min(ans,front - minm);
            minm = min(minm,front / 2);
            pq.push(front / 2);
        }
        ans = min(ans,pq.top() - minm);
        return ans;
    }
};
