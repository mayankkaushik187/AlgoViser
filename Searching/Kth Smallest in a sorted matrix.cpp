//Leetcode 378

int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = matrix[0][0];
        int end = matrix[row-1][col-1];
        
        while(start <= end){
            int MID = (start + end) / 2;
            int ans = 0;
            for(int i = 0 ; i < row ; i++){
                int low = 0;
                int high = col - 1;
                while(low <= high){
                    int mid = low + (high - low)/2;
                    if(matrix[i][mid] <= MID){
                        low = mid + 1;
                    }else{
                        high = mid - 1;
                    }
                }
                ans += low;
            }
            if(ans < k){
                start = MID + 1;
            }else {
                end = MID - 1;
            }
        }
        return start;
    }
