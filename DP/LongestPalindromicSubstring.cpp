/*


Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.


  */

string longestPalindrome(string s) {

        int i = 0, l = 0, r = 0, maxL = 0, n = s.size();
        string maxLstr = "";

        while(i < n){
            l = i, r = i;
            while(l >= 0 && r<n && s[l] == s[r]){
                if(maxL < r-l+1){
                    maxL = r-l+1;
                    maxLstr = s.substr(l, r-l+1);
                }
                l--, r++;
            } 
            i++;
        }
        i = 0, l = 0, r = 0;
        while(i < n){
            l = i, r = i+1;
            while(l >= 0 && r<n && s[l] == s[r]){
                if(maxL < r-l+1){
                    maxL = r-l+1;
                    maxLstr = s.substr(l, r-l+1);
                }
                l--, r++;
            } 
            i++;
        }
        return maxLstr;
    }
