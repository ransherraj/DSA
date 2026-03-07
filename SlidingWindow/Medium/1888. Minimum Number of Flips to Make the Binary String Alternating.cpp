/*

1888. Minimum Number of Flips to Make the Binary String Alternating
You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
 

Example 1:

Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
Example 2:

Input: s = "010"
Output: 0
Explanation: The string is already alternating.
Example 3:

Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.

*/


/*

****Important Trick in Code

The code counts how many characters mismatch with alternating pattern.

But instead of comparing with "010101" and "101010" strings, it uses a bit trick.

Look here:

(s[i] ^ i) & 1

Why?

Because:

pattern 010101...
index: 0 1 2 3 4
value: 0 1 0 1 0

For this pattern:

expected = i % 2

Now compare with actual char.

Since '0' = 48 and '1' = 49 in ASCII, using XOR works nicely.

Result gives whether bit matches pattern or not.

4. Variables in Code
int op[2] = {0, 0};

Meaning:

op[0] = flips needed for pattern starting with '0'
op[1] = flips needed for pattern starting with '1'
5. First Loop (Initial Count)
for (int i = 0; i < n; i++)
    op[(s[i] ^ i) & 1]++;

This calculates mismatch count for original string.

Example

s = 111000
index : 0 1 2 3 4 5
char  : 1 1 1 0 0 0
pattern A (010101)
pattern B (101010)

It counts mismatches.

6. Why Second Loop Exists

Second loop simulates rotation using sliding window.

for (int i = 0; i < n; i++) {

Each iteration = one rotation

Step 1 — Remove first element from window
op[(s[i] ^ i) & 1]--;

Because this character moves from front to back.

Step 2 — Add same character at new position
op[(s[i] ^ (n + i)) & 1]++;

Why (n+i)?

Because after rotation, the character moves to end.

So its new index becomes n+i.

Step 3 — Update answer
res = min(res, min(op[0], op[1]));

Meaning:

Take best result between
pattern 010101...
pattern 101010...
7. Example Walkthrough

Input:

s = 111000

Length

n = 6

Possible alternating patterns

010101
101010

Try rotations.

Best rotation becomes:

100011

Then flip:

100011
↓
101010

Flips needed = 2

8. Why This Solution Is Fast

Instead of checking all rotations separately:

Normal approach = O(n²)

This method uses sliding window:

Time complexity = O(n)
Space = O(1)

Which works for

n ≤ 100000
9. One Small Improvement

Your function signature:

int minFlips(auto& s)

Should be written as:

int minFlips(string& s)

Because auto is not allowed here in many compilers.

10. Final Simplified Idea

Algorithm in simple steps:

Count mismatches with alternating pattern.

Rotate string logically using sliding window.

Update mismatch counts.

Track minimum flips.

11. Intuition in One Line

We check every rotation of the string and compute minimum flips required to convert it into alternating form using a sliding window trick.

If you want, I can also show:

Very easy brute force solution (for understanding)

Visual dry run of this code

Why (s[i] ^ i) & 1 works mathematically

These will make this code crystal clear.

  */


class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), ans = n;
        vector<int> best = {0, 0};
        for(int i = 0; i<n; i++){
            best[(s[i] ^ i) & 1 ]++; // this checks number of bits matched with 010101.... in the prvided string
        }

        for(int i = 0; i<n; i++){
            best[(s[i] ^ i) & 1 ]--;  // shift one index to right by removing at i
            best[(s[i] ^ (n+i)) & 1 ]++;  // shift one index to right by adding at n+i
            ans = min(ans, min(best[0], best[1])); // choose best
        }
        return ans;
    }
};
