/*

695. Max Area of Island
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/


class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int m, int n, int &ans){
        if(i<0 || j<0 || i>=m || j>=n || !grid[i][j] || vis[i][j]) return;
        vis[i][j] = 1;
        ans += 1;
        dfs(grid, vis, i+1, j, m, n, ans);
        dfs(grid, vis, i-1, j, m, n, ans);
        dfs(grid, vis, i, j+1, m, n, ans);
        dfs(grid, vis, i, j-1, m, n, ans);

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0, maxx = 0;
        vector<vector<int>> vis(m, vector<int>(n));
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!vis[i][j] && grid[i][j]){
                    ans = 0;
                    dfs(grid, vis, i, j, m, n, ans);
                    maxx = max(maxx, ans);
                    //cout<<maxx<<" ";
                }
            }
        }
        return maxx;
    }
};
