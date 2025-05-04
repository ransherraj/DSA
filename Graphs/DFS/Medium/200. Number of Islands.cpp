/*

200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/

class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>> &vis, int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]-'0' == 0 || vis[i][j]){
            return;
        }
        vis[i][j] = 1;
        dfs(grid, vis, i+1, j, m, n);
        dfs(grid, vis, i-1, j, m, n);
        dfs(grid, vis, i, j+1, m, n);
        dfs(grid, vis, i, j-1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] - '0' == 1 && !vis[i][j]){
                    ans++;
                    dfs(grid, vis, i, j, m, n);
                }
            }
        }
        return ans;
    }
};
