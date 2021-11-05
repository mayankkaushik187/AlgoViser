//Leetcode 2024
class Solution {
public:
    int helper(string str,int k,char ch){
        int i = 0;
        int maxm = 0;
        int curr = 0;
        for(int j = 0 ; j < str.size() ; j++){
            curr += str[j] == ch;
            while(curr > k){
                curr -= str[i++] == ch;
            }
            maxm = max(maxm,j - i + 1);
        }
        return maxm;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper(answerKey,k,'T'),helper(answerKey,k,'F'));
    }
};
