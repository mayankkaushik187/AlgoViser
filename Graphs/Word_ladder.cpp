class Solution {
public:
  //leetcode 127
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        int ans = 1;
        q.push(beginWord);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i < n ; i++){
                auto curr = q.front();
                q.pop();
                if(curr == endWord){
                    return ans;
                }
                st.erase(curr);
                for(int j = 0 ; j < curr.size() ; j++){
                    char temp = curr[j];
                    for(int k = 0 ; k < 26 ; k++){
                        curr[j] = 'a' + k;
                        if(st.find(curr)!=st.end()){
                            st.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[j] = temp;
                }
            }
            ans++;
        }
        return 0;
    }
};
