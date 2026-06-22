class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size()-1;
        int ans = 0;
        while(left<right){
            int len = right-left;
            int bre = min(heights[left], heights[right]);
            ans = max(ans, len*bre);
            if(heights[left] < heights[right]) left++;
            else if(heights[right] < heights[left]) right--;
            else {left++; right--;}
        }
        return ans;
    }
};
