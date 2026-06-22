class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<map<char,int>, vector<string>> mp;
        for(auto s: strs){
            map<char, int> m;
            for(auto i: s) m[i]++;
            mp[m].push_back(s);
        }
        for(auto i: mp){
            vector<string> tmp;
            for(auto s: i.second){
                tmp.push_back(s);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
