class Solution {
public:
    int fn(vector<int>& nums,  int num, unordered_map<int,int>& mp){
        if(mp.find(num) != mp.end()) return mp[num];
        int tmp=1;
        while(find(nums.begin(), nums.end(), num+1) != nums.end()){
            mp[num+1] = tmp;
            tmp++;
            num++;
        }
        return tmp;

    }
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])!=mp.end()) continue;
            int tmp = fn(nums, nums[i],mp);
            ans = max(ans, tmp);
            mp[nums[i]] = tmp;
        }
        return ans;
    }
};
