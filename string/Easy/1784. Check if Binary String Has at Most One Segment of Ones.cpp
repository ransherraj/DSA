/*** 1784. Check if Binary String Has at Most One Segment of Ones


Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

 

Example 1:

Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.
Example 2:

Input: s = "110"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i]​​​​ is either '0' or '1'.
s[0] is '1'.

  ****/

class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        bool hasZeroAppeared = false;
        for(int i = 1; i<n; i++){
            if(s[i] == '1' && !hasZeroAppeared) {
                continue;
            }
            if(s[i] == '0') {
                hasZeroAppeared = true;
            }
            if(hasZeroAppeared && s[i] == '1') return false;
        }
        return true;
    }
};
