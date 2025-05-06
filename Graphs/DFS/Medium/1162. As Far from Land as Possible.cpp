/*

1162. As Far from Land as Possible
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

 

Example 1:


Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
Example 2:


Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1


*/


class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j, int dist = 1){
        int m = grid.size(), n = grid[0].size();
        
        if(i<0 || j<0 || i>=m || j>=n || (grid[i][j] != 0 && grid[i][j] <= dist)){
            return;
        }
        grid[i][j] = dist;
        dfs(grid, i+1, j, dist+1);
        dfs(grid, i-1, j, dist+1);
        dfs(grid, i, j+1, dist+1);
        dfs(grid, i, j-1, dist+1);
    }

    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = -1;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    dfs(grid, i, j);
                }
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] > 1) ans = max(ans, grid[i][j]-1);
            }
        }
        return ans;
    }
};
