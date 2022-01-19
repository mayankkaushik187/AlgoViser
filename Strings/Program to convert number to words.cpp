#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<string> ones = {"","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ","thirteen ","fourteen ","fifteen ","sixteen " ,"seventeen ","eighteen ","nineteen "};
    vector<string> tens = {"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};
public:
    
    string conversion(int n,string s){
        string res = "";
        if(n > 19){
            res += tens[n / 10] + ones[n % 10];
        }else{
            res += ones[n];
        }
        if(n){
            res += s;
        }
        return res;
    }
    string convertToWords(long n) {
        // code here
        string output = "";
        
        output += conversion((n / 10000000) , "crore ");
        output += conversion((n / 100000) % 100 , "lakh ");
        output += conversion((n / 1000) % 100 , "thousand ");
        
        output += conversion((n / 100) % 10 , "hundred ");
        
        if(n > 100 and n % 100){
            output += "and ";
        }
        output += conversion((n) % 100,"");
        
        return output == "" ? "zero" : output;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
