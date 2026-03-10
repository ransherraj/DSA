/**

62. Unique Paths
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100

**/


//Brute force

class Solution {
public:
    void dfs(int m, int n, int i, int j, int &ans){
        if(i >= m || j >= n) return;
        if((i == m-1 && j == n-1)){
            ans++;
        }
        
        dfs(m, n, i+1, j, ans); 
        dfs(m, n, i, j+1, ans);
    }
    int uniquePaths(int m, int n) {
        int ans = 0;
        dfs(m, n, 0, 0, ans);
        return ans;
    }
};

//optimised with dp

class Solution {
private:
    int dp[101][101];
public:

    int dfs(int m, int n, int i, int j){
        if(i >= m || j >= n) return 0;
        if((i == m-1 && j == n-1)){
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        //dp[i][j] = ans;
        
        return dp[i][j] = dfs(m, n, i+1, j) + dfs(m, n, i, j+1);
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        int ans = dfs(m, n, 0, 0);
        return ans;
    }
};
