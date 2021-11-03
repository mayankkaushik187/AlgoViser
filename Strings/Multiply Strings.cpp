class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0")return "0";
        vector<int> ans(num1.size() + num2.size(),0);
        for(int i = num1.size() - 1; i >= 0 ; i--){
            for(int j = num2.size() - 1 ; j >= 0 ; j--){
                int valIdx = i + j + 1; // num1.sizE() + num2.size() - 1 will be the last index of our ans arr
                int remIdx = i + j;//1 less than valIdx
                int product = (num1[i] - '0') * (num2[j] - '0');
                product += ans[valIdx];
                ans[valIdx] = product%10;
                ans[remIdx] += product/10;
            }
        }
        string res = "";
        bool preceedingzero = true;
        for(int i = 0 ; i < ans.size() ; i++){
            int val = ans[i];
            if(val != 0)preceedingzero = false;
            if(!preceedingzero)res += to_string(val);
        }
        return res;
    }
};
