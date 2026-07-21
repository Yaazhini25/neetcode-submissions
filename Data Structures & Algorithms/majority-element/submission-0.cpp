class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand=-1, cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(cand==-1 || cand == nums[i]){
                cand = nums[i];
                cnt++;
            }
            else cnt--;
            if(cnt<0) {
                cand = nums[i];
                cnt++;
            }
        }
        return cand;
    }
};