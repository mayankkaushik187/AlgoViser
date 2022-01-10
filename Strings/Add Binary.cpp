class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size())swap(a,b);
        
        int diff = a.size() - b.size();
        while(diff--){
            b = "0" + b;
        }
        // cout<<b;
        string res = "";
        int n = a.size();
        int i = n - 1;
        char carry = '0';
        while(i >= 0){
            if(a[i] == b[i]){
                if(a[i] == '1'){
                    if(carry == '1'){
                        res += (a[i] == '1') ? '1' : '0';
                    }else{
                        res += '0';
                    }
                    carry = '1';
                }else{
                    res += carry == '1' ? '1' : '0';
                    carry = '0';
                }
            }else{
                res += (carry == '1') ? '0': '1';
                if(res.back() == '0'){
                    carry = '1';
                }
                else carry = '0';
            }
            i--;
        }
        if(carry == '1'){
            res += '1';
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
