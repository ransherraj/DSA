

/*

713. Subarray Product Less Than K
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Example 2:

Input: nums = [1,2,3], k = 0
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106
*/

// O(n^2) in most case go for TLE
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i<n; i++){
            long long prod = 1;
            for(int j = i; j<n; j++){
                prod *= nums[j];
                if(prod < k){
                    ans++;
                }else if(prod >= k){
                    break;
                }
            }
        }
        return ans;
    }
};

// Most efficient approach (Sliding window) => O(2*n) maximum
// The idea is to start taking of each element of array from begining and check if it less than k, 
// if yes => while loop skips, closely looking at pattern that subarray sum is following pattern as
// if 1 element => contribution to ans 1
// if 2 element => contribution to ans 1 + 2
// if 3 element => contribution to ans 1 + 2 + 3 and so on.....
// this can be solved easily as ans += (i - j + 1)
// now, if no => it enters to while loop, and j start from begining and starts skipping array elements till again it enters in prod < k
// This way two pointer approach does the task in great manner.
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, j = 0;
        long long prod = 1;
        for(int i = 0; i<n; i++){
            prod *= nums[i];
            while(j <= i && prod >= k){
                prod /= nums[j++];
            }
            ans += (i - j + 1);
        }
        return ans;
    }
};


