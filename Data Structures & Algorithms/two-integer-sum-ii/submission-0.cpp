class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int l=0, r=numbers.size()-1;
        while(l<r){
            int summ = numbers[l] + numbers[r];
            if(summ == target) {
                return {l+1, r+1};
            }
            if(summ<target) l++;
            else r--;
        }
        return {};
    }
};
