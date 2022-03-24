class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int n = people.size();
        sort(people.begin(),people.end());
        int i = 0, j = n - 1;
        while(i <= j){
            ans++;
            if(people[i] + people[j] <= limit)i++;
            j--;
        }
        return ans;
    }
};
