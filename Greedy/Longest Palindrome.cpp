//Leetcode 409

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        int ans = 0;
        for(auto x : s){
            if(st.find(x)!=st.end()){
                auto it = st.find(x);
                st.erase(it);
                ans++;
            }else{
                st.insert(x);
            }
        }
        if(st.size() != 0)return 2*ans + 1;
        return 2 * ans;
    }
};
