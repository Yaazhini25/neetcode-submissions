class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> ss, tt;
        for(auto i:s) ss[i]++;
        for(auto i:t) tt[i]++;
        for(auto i: ss){
            if(tt[i.first] != i.second) return false;
        }
        for(auto i: tt){
            if(ss[i.first] != i.second) return false;
        }
        return true;
    }
};
