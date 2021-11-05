//Leetcode 784
class Solution {
public:
    void helper(string s,vector<string>&res,string temp,int pos){
        if(pos == s.size()){
            res.push_back(temp);
            return;
        }
        if(temp[pos] >= '0' and temp[pos] <= '9'){
            helper(s,res,temp,pos+1);
            return;
        }
        char ch = temp[pos];
        temp[pos] = tolower(ch);
        helper(s,res,temp,pos+1);
        ch = temp[pos];
        temp[pos] = toupper(ch);
        helper(s,res,temp,pos+1);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string temp = s;
        helper(s,res,temp,0);
        return res;
    }
};
