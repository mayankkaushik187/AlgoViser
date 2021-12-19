class Solution {    
private:
    string helper(string &s,int &i){
        string ans = "";
        while(i < s.size() and s[i] != ']'){
            if(!isdigit(s[i])){
                ans += s[i++];
            }else{
                int val = 0;
                while(i < s.size() and isdigit(s[i])){
                    val = 10 * val + s[i++] - '0';
                }
                i++;
                string sans = helper(s,i);
                i++;
                while(val--){
                    ans += sans;
                }
            }
        }
        return ans;
    }
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s,i);
    }
};
