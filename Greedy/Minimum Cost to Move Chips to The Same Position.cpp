class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int eveCount = 0,oddCount = 0;
        int n = position.size();
        for(int i = 0 ; i < n ; i++){
            if(position[i] % 2 == 1)oddCount++;
            else eveCount++;
        }
        return min(eveCount,oddCount);
    }
};
