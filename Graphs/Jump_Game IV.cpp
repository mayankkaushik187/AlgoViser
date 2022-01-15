class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = int(arr.size());
        unordered_map<int,vector<int> > mp;
        for(int i = 0 ; i < int(arr.size()) ; i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vector<int> visited(n,0);
        visited[0] = 1;
        int steps = 0;
        while(!q.empty()){
            for(int i = q.size() ; i > 0 ; i--){
                int curr_idx = q.front();
                q.pop();
                if(curr_idx == n - 1){
                    return steps;
                }
                vector<int>& next = mp[arr[curr_idx]];
                next.push_back(curr_idx + 1);
                next.push_back(curr_idx - 1);
                for(auto &x : next){
                    if(x < n and x >= 0 and !visited[x]){
                        visited[x] = 1;
                        q.push(x);
                    }
                }
                next.clear();
            }
            steps++;
        }
        return 0;
    }
};
