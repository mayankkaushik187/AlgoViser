class Solution {
public:
    void helper(int open,int close,string str,vector<string>&res){
        if(open == 0 and close == 0){
            res.push_back(str);
            return;
        }
        if(open > 0){
            helper(open-1,close,str + '(',res);
        }
        if(close > open){
            helper(open,close-1,str + ')',res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str = "";
        helper(n,n,str,res);
        return res;
    }
};
