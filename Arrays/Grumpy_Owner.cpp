//Leetcode 1052
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int maxm = 0;
        vector<int> lsum(n,0),rsum(n,0);
        //Calc prefix sum of satisfied customers 
        for(int i = 0 ; i < n ; i++){
            if(i >= 1)
                lsum[i] = lsum[i-1] + customers[i]*(!grumpy[i]);
            else
                lsum[i] = (!grumpy[i])*customers[i];
        }
        //Calc suffix sum of satisfied customers
        for(int i = n - 1 ; i >= 0 ; i--){
            if(i <= n - 2)
                rsum[i] = rsum[i+1] + customers[i]*(!grumpy[i]);
            else
                rsum[i] = (!grumpy[i])*customers[i];
        }
        int val = 0;
        for(int i = 0 ; i < n ; i++){
            //increase window by 1
            val += customers[i];
            int temp1 = 0, temp2 = 0;
            if(i >= minutes){
                //decrease window by 1
                val -= customers[i - minutes];
                //store the sum of satisifed customers just one index behind the start of the window
                temp2 = lsum[i-minutes];
            }
            //store the sum of satisfied customers just one index ahead of the window
            temp1 = (i + 1 < n and i >= minutes - 1) ? rsum[i+1] : 0;
            //add to the curr window ans
            val += temp1 + temp2;
            //Relax the maximum ans
            maxm = max(maxm,val);
            //subtract the prefix and suffix values so that it dont get added in the next iteration's ans
            val -= temp1;
            val -= temp2;
        }
        return maxm;
    }
	
};
