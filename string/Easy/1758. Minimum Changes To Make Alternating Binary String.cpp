/***
You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.

 

Example 1:

Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.
Example 2:

Input: s = "10"
Output: 0
Explanation: s is already alternating.
Example 3:

Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".
 

Constraints:

1 <= s.length <= 104
s[i] is either '0' or '1'.
***/


//Since there are only two valid alternating patterns:

// We can write each mismatch count as as:

// count= 
// int (0 or 1)
// (s[i] & 1)​
//   ⊕ 
// index parity
// (i & 1)





class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), cnt = 0;
        for(int i = 0; i<n; i++){
            int oebit = i & 1;
            int charbit = (s[i] - '0');
            cnt += (oebit ^ charbit);
        }
        return min(cnt, n-cnt);
    }
};
