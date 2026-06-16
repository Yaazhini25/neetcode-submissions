class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int& cnt, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j]) return;
        cnt++;
        visited[i][j] = 1;
        //right
        if(j+1 < grid[0].size() && grid[i][j+1] && !visited[i][j+1]) dfs(grid, visited, cnt, i, j+1);
        //left
        if(j-1 >=0 && grid[i][j-1] && !visited[i][j-1]) dfs(grid, visited, cnt, i, j-1);
        //up
        if(i-1 >=0 && grid[i-1][j] && !visited[i-1][j]) dfs(grid, visited, cnt, i-1, j);
        //down
        if(i+1 < grid.size() && grid[i+1][j] && !visited[i+1][j]) dfs(grid, visited, cnt, i+1, j);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] && !visited[i][j]){
                    int cnt = 0;
                    dfs(grid, visited, cnt, i, j);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};
