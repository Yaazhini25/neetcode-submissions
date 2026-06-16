class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j]) return;
        visited[i][j] = 1;
        //right
        if(j+1 < grid[0].size()   &&  grid[i][j+1]=='1' && !visited[i][j+1]) dfs(grid, visited, i, j+1);
        //left
        if(j-1 >=0   && grid[i][j-1]=='1' && !visited[i][j-1]) dfs(grid, visited, i, j-1);
        //up
        if(i-1>=0 && grid[i-1][j]=='1' && !visited[i-1][j]) dfs(grid, visited, i-1, j);
        //down
        if(i+1<grid.size() && grid[i+1][j]=='1' && !visited[i+1][j]) dfs(grid, visited, i+1, j); 

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    ans++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return ans;
    }
};
