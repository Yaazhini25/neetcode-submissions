class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>> &pacific, int i, int j){
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size() || pacific[i][j]==1) return;
        pacific[i][j]=1;
        //right
        if(j+1<heights[0].size() && heights[i][j+1]>=heights[i][j]) {
            dfs(heights, pacific, i, j+1);
        }
        //left
        if(j-1>=0 && heights[i][j-1]>=heights[i][j]){
            dfs(heights, pacific, i, j-1);
        }
        //up
        if(i-1>=0 && heights[i-1][j]>=heights[i][j]){
            dfs(heights, pacific, i-1, j);
        }
        //down
        if(i+1<heights.size() && heights[i+1][j]>=heights[i][j]){
            dfs(heights, pacific, i+1, j);
        }
        return;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> pacific(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> atlantic(heights.size(), vector<int>(heights[0].size(), 0));
        
        for(int i=0; i<heights[0].size(); i++){
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, heights.size()-1, i);
        }
        for(int i=0; i<heights.size(); i++){
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, heights[0].size()-1);
        }
        
        for(int i=0; i<heights.size(); i++){
            for(int j=0; j<heights[0].size(); j++) cout<<atlantic[i][j]<<" ";
            cout<<"\n";
        }
        vector<vector<int>> ans;
        for(int i=0; i<heights.size(); i++){
            for(int j=0; j<heights[0].size(); j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
