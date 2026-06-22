class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0, rmax = 0;
        int left=0, right = height.size()-1;
        int ans = 0;
        for(int i=0; i<height.size(); i++){
            lmax = max(lmax, height[left]);
            rmax = max(rmax, height[right]);
            ans += min(lmax, rmax)-height[i];
            if(height[left] < height[right]) left++;
            else right--;
        }
        return ans;
    }
};
