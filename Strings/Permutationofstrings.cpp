class Solution {
public:
    bool matches(int s1map[],int s2map[]){
        for(int i = 0 ; i < 26 ; i++){
            if(s1map[i] != s2map[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())return false;
        int s1map[26] = {0};
        for(int i = 0 ; i < s1.size() ; i++){
            s1map[s1[i]-'a']++;
        }

        for(int i = 0 ; i <= s2.size() - s1.size() ; i++){
            int s2map[26] = {0};
            for(int j = 0 ; j < s1.size() ; j++){
                s2map[s2[i+j] - 'a']++;
            }
            if(matches(s1map,s2map))return true;
        }
        
        return false;
    }
};
