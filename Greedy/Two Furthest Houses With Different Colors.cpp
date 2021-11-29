class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i = 0;
        int n = colors.size();
        int j = colors.size() - 1;
        while(colors[0] == colors[j])j--;
        while(colors[n-1] == colors[i])i++;
        
        return max(abs(n - 1 - i),abs(j - 0));
    }
};
