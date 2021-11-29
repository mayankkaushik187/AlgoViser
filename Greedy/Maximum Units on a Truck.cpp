class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
        sort(boxes.begin(),boxes.end(),[&](vector<int>&a, vector<int>&b){
            return a[1] > b[1];
        });
        int ans = 0, i = 0;
        while(truckSize!=0 and i < boxes.size()){
            if(boxes[i][0] > 0){
                ans += boxes[i][1];
                truckSize--;
                boxes[i][0]--;
            }else{
                i++;
            }
        }
        return ans;
        
    }
};
