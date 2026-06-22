class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> ss;
        for(auto i:s) ss[i]++;
        for(auto i: t){
            ss[i]--;
            // what if t has extra chars
            if(ss[i]<0) return false;
        }
        for(auto i: ss){
            // what if s has extra chars
            if(i.second>0) return false;
        }
        return true;
    }
};
