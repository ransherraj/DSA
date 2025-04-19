/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000

*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++){
            mp[arr[i]]++;
        }
        for(auto x : mp){
            ans.push_back(x.second);
        }
        sort(ans.begin(), ans.end());
        for(int i = 1; i<ans.size(); i++){
            if(ans[i-1] == ans[i]) return false;
        }
        
        return true;
    }
};
