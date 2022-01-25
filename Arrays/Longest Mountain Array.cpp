LC 845
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i = 0;
        int n = arr.size();
        int ans = 0;
        while (i < n){
            int temp = i;
            if(i + 1 < n and arr[i] < arr[i + 1]){
                while(i + 1 < n and arr[i] < arr[i + 1]){
                    i++;
                }
                if(i + 1 < n and arr[i] > arr[i + 1]){
                    while(i + 1 < n and arr[i] > arr[i + 1]){
                        i++;
                    }
                    ans = max(ans, i - temp + 1);
                }
            }
            if(i == temp)i++;
        }
        return ans;
    }
};

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size() < 3)return 0;
        int n = arr.size();
        int i = 1;
        int maxm = 0;
        while(i < n - 1){
            int l = i, r = i;
            while(l >= 0){
                if(l - 1 >= 0 and arr[l - 1] < arr[l])l--;
                else break;
            }
            while(r < n){
                if(r + 1 < n and arr[r + 1] < arr[r])r++;
                else break;
            }
            if(r > i and l < i and r - l + 1 >= 3)
                maxm = max(maxm,r - l + 1);
            i = r + 1;
        }
        return maxm;
    }
};
