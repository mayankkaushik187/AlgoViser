#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 
  
// Declaring ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, 
            tree_order_statistics_node_update> 
    ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
            tree_order_statistics_node_update> 
    or_set; 
class Solution {
public:
    vector<int> countSmaller(vector<int>& arr) {
        int n = (int)arr.size();
        or_set st;
        vector<int> res(n,0);
        st.insert(arr[n-1]);
        res[n - 1] = 0;
        for(int i = n - 2; i >= 0 ; i--){
            res[i] = st.order_of_key(arr[i]);
            
            st.insert(arr[i]);
        }
        return res;
    }
};
