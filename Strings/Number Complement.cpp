class Solution {
public:
    string make_string (int num){
        string s = "";
        while(num){
            s += to_string(num % 2);
            num /= 2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int findNum(string s){
        int ans = 0;
        int n = s.size();
        for(int i = n - 1 ; i >= 0 ; i--){
            ans +=(s[i] - '0') * pow(2,n - i - 1); 
        }
        return ans;
    }
    int findComplement(int num) {
        string s = make_string(num);
        int n = s.size();
        for(int i= 0 ; i < n; i ++){
            s[i] = s[i] == '1' ? '0' : '1';
        }
        
        return findNum(s);
    }
};
