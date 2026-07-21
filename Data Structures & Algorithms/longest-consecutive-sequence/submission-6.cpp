class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> sett(nums.begin(), nums.end());
        for(auto i:sett){
            if(!sett.count(i-1)){
                int tmp = 1, val=i;
                while(sett.count(i+1)){
                    tmp++;
                    i++;
                }
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
