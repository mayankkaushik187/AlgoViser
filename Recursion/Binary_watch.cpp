class Solution {
    public:
  //Leetcode 401
        void helper(vector < int > & h1, int digits, int index, int sum, vector < int > & temp) {
            if (digits == 0) {
                temp.push_back(sum);
                return;
            }
            for (int i = index; i < h1.size(); i++) {
                helper(h1, digits - 1, i + 1, sum + h1[i], temp);
            }
        }
    vector < int > generateDigits(vector < int > & h1, int digits) {
        vector < int > temp;
        int index = 0, sum = 0;
        helper(h1, digits, index, sum, temp);
        return temp;
    }
    vector < string > readBinaryWatch(int turnedOn) {
        vector < string > res;
        vector < int > h = {
            1,
            2,
            4,
            8
        };
        vector < int > m = {
            1,
            2,
            4,
            8,
            16,
            32
        };
        for (int i = 0; i <= turnedOn; i++) {
            vector < int > l1 = generateDigits(h, i);
            vector < int > l2 = generateDigits(m, turnedOn - i);

            for (int x: l1) {
                if (x >= 12) continue;
                for (int y: l2) {
                    if (y >= 60) continue;
                    string s1 = '0' + to_string(y);
                    string m = (y < 10) ? s1 : to_string(y);
                    string str = to_string(x) + ":" + m;
                    res.push_back(str);
                }
            }
        }
        return res;
    }
};
