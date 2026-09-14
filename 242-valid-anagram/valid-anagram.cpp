class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        if(s.length()!=t.length()){
            return false;
        }
        for(char c : s){
            m[c]++;
        }
        for(char c : t){
            m[c]--;
        }
        for(auto pair : m){
            if(pair.second != 0){
                return false;
            }
        }

     return true;    
    }
};