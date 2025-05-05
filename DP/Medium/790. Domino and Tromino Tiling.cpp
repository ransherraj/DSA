/*
790. Domino and Tromino Tiling
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are show above.
Example 2:

Input: n = 1
Output: 1


*/


// Recursion => TLE
class Solution {
public:
    const int MOD = 1e9+7;
    int numTilings(int n) {
        return solve(0, n, false);
    }
    long solve(int i, int n, bool previousGap) {
        if(i > n) return 0;                 // previous tiling exceeded bounds of grid - return 0 denoting not a valid tiling
        if(i == n) return !previousGap;     // return 1 when there was no previous gap present
        if(previousGap)                     // previous column had gap remaining in it
            return (solve(i+1, n, false) + solve(i+1, n, true)) % MOD;
        return (solve(i+1, n, false) + solve(i+2, n, false) + 2l*solve(i+2, n, true)) % MOD;
    }
};


// Memoised
class Solution {
public:
    const int MOD = 1e9+7;
    int dp[1001][2]{};
    int numTilings(int n) {
        return solve(0, n, false);
    }
    long solve(int i, int n, bool previousGap) {
        if(i > n) return 0;                 // previous tiling exceeded bounds of grid - return 0 denoting not a valid tiling
        if(i == n) return !previousGap;     // return 1 when there was no previous gap present
        if(dp[i][previousGap]) return dp[i][previousGap];
        if(previousGap)                     // previous column had gap remaining in it
            return dp[i][previousGap] = (solve(i+1, n, false) + solve(i+1, n, true)) % MOD;
        return dp[i][previousGap] = (solve(i+1, n, false) + solve(i+2, n, false) + 2l*solve(i+2, n, true)) % MOD;
    }
};
