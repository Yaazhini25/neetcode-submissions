class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0, n=nums.size();
        unordered_set<int>numss (nums.begin(), nums.end());
        for(auto i: numss){
            int tmp=0, num=i;
            if(numss.find(num-1) == numss.end()){
                    while(numss.find(num) != numss.end()){
                        tmp++;
                        num++;
                }
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
