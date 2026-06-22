class Solution {
public:
    int fn(vector<int>& nums,  int num){
        int tmp=1;
        while(find(nums.begin(), nums.end(), num+1) != nums.end()){
            tmp++;
            num++;
        }
        return tmp;

    }
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            int tmp = 1;
            ans = max(ans, fn(nums, nums[i]));
        }
        return ans;
    }
};
