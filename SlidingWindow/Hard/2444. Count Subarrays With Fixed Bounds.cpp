/*
2444. Count Subarrays With Fixed Bounds
You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
Example 2:

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
 

Constraints:

2 <= nums.length <= 105
1 <= nums[i], minK, maxK <= 106


*/

// Brute Force (TLE)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i<n; i++){
            int maxx = INT_MIN, minn = INT_MAX;
            for(int j = i; j<n; j++){
                minn = min(minn, nums[j]);
                maxx = max(maxx, nums[j]);
                if(minn == minK && maxx == maxK){
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Optimized using sliding window 
// (The approach is too keep track of indexes of minK and maxK appeared earlier,
// if both appeared then, contribute to answer. If any invalid index 
// comes in btween then it alters the result)
// For reference watch https://www.youtube.com/watch?v=BTk6_WBc4Ig

class Solution {
public:
    
    int max(int a, int b){
        return a > b ? a : b;
    }
    int min(int a, int b){
        return a < b ? a : b;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0, minI = -1, maxI = -1, invI = -1;
        for(int i = 0; i<n; i++){
            if(nums[i] == minK) minI = i;
            if(nums[i] == maxK) maxI = i;
            if( nums[i] < minK || nums[i] > maxK) invI = i;
            ans += max( (min(minI, maxI) - invI ), 0);
        }
        return ans;
    }
};
