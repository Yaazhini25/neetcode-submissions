class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == k) return nums;
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        vector<vector<int>> buckets(n+1);
        for(auto i: mp){
            buckets[i.second].push_back(i.first);
        }
        for(int i=n; (i>=0 && k); i--){
            for(auto ele:buckets[i]) {ans.push_back(ele); k--;}
        }
        return ans;
    }
};
