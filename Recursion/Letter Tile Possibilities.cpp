//Leetcode 1079
class Solution {
public:
    void dfs(string tiles,unordered_set<string>&s,int index){
        for(int i = index ; i < tiles.size() ; i++){
            swap(tiles[i],tiles[index]);
            s.insert(tiles.substr(0,index+1));
            dfs(tiles,s,index+1);
            swap(tiles[i],tiles[index]);
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_set<string> s;
        dfs(tiles,s,0);
        return s.size();
    }
};
