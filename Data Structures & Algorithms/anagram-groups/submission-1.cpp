class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mapp;
        for(auto i: strs){
            string tmp = i;
            sort(tmp.begin(), tmp.end());
            mapp[tmp].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto i: mapp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
