class WordDictionary {
    unordered_map<int,vector<string>> mp;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word.size()].push_back(word);        
    }
    
    bool search(string word) {
        int size = word.size();
        for(auto &x : mp[size]){
            int ans = 1;
            for(int i = 0 ; i < size ; i++){
                if(word[i] == '.')continue;
                if(word[i] != x[i])ans = 0;
            }
            if(ans){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
