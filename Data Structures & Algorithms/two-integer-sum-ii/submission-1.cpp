class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        while(i<j){
            int summ = nums[i]+nums[j];
            if(summ == target) return {i+1,j+1};
            else if(summ>target) j--;
            else i++;
        }
        return {};
    }
};
