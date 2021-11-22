class Solution {
public:
  //leetcode 60
    // Our recursive function that will complete the ans string.
	// v - is our current array = [1,2,3,4]
	// ans is the answer string, n and k are current values of n and k
	// factVal is an array containing the factorial of all integers from 0-9 to get factorial in O(1) time.
	// That means I have stored all the factorials in this array before hand to avoid calculation. You can also write factorial funciton if you want.
	
    void setPerm(vector<int>& v,string& ans,int n,int k,vector<int>& factVal){
       // if there is only one element left append it to our ans (Base case)
	   if(n==1){
            ans+=to_string(v.back());
            return;
        }
		
		// We are calculating the required index.  factVal[n-1] means for n =  4 => factVal[3] = 6.
        // 15 / 6 = 2 will the index for k =15 and n = 4.
		int index = (k/factVal[n-1]);
        // if k is a multiple of elements of partition then decrement the index (Corner case I was talking about)
		if(k % factVal[n-1] == 0){
            index--;
        }
		
		ans+= to_string(v[index]);  // add value to string
        v.erase(v.begin() + index);  // remove element from array
        k -= factVal[n-1] * index;   // adjust value of k; k = 15 - 6*2 = 3.
		// Recursive call with n=n-1 as one element is added we need remaing.
        setPerm(v,ans,n-1,k,factVal);
    }
    
    string getPermutation(int n, int k) {
        if(n==1) return "1";
		//Factorials of 0-9 stored in the array. factVal[3] = 6. (3! = 6)
        vector<int>factVal = {1,1,2,6,24,120,720,5040,40320,362880};
        string ans = "";
        vector<int> v;
		// Fill the array with all elements
        for(int i=1;i<=n;i++) v.emplace_back(i);
        setPerm(v,ans,n,k,factVal);
        return ans;
    }
};
