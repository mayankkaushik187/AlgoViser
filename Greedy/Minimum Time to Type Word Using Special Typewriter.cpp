class Solution {
public:
//leetcode 1974
    int minTimeToType(string word) {
        int time = word.size();
        char prev = 'a';
        for(char &x : word){
            time += min(abs(x - prev),26 - abs(prev - x));
            prev = x;
        }
        return time;
    }
};
