#include<bits/stdc++.h>
using namespace std;

vector<int> Solution::equal(vector<int> &A) {
    vector<vector<int>> res;
    unordered_map<int,pair<int,int>> mp;
    for(int i = 0 ; i < A.size() - 1 ; i++){
        for(int j = i + 1 ; j < A.size() ;j++){
            if(mp.find(A[i] + A[j])!=mp.end()){
                int x = mp[A[i] + A[j]].first , y = mp[A[i] + A[j]].second;
                if(x<y&&i<j&&x<i&&y!=i&&y!=j){
                    vector<int> temp = {x,y,i,j};
                    res.push_back(temp);
                }
            }else{
                mp[A[i] + A[j]] = {i,j};
            }
        }
    }
    if(res.size() == 0){
        return {};
    }
    sort(res.begin(),res.end());
    return res[0];
    
}
