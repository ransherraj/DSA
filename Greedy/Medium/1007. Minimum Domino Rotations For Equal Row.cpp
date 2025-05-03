/*

1007. Minimum Domino Rotations For Equal Row
In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.

 

Example 1:


Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 

Constraints:

2 <= tops.length <= 2 * 104
bottoms.length == tops.length
1 <= tops[i], bottoms[i] <= 6

*/


class Solution {
public:
    int getAnswer(vector<int>& top, vector<int>& bot, int maxEle, int &ans){
        int n = top.size();
        for(int i = 0; i<n; i++){
            if(top[i] != maxEle ) {
                if(bot[i] != maxEle){
                    return -1;
                }else{
                    ans++;
                }
            }
        }
        return ans;
    }
    int minDominoRotations(vector<int>& top, vector<int>& bot) {
        int n = top.size(), maxEle = 0, maxCnt = 0, ans = 0;
        bool isTop = true;
        unordered_map<int, int>mp1, mp2;
        for(int i = 0; i<n; i++){
            mp1[top[i]]++, mp2[bot[i]]++;
        }
        for(auto x : mp1){
            if(x.second > maxCnt){
                maxCnt = x.second;
                maxEle = x.first;
            }
        }
        for(auto x : mp2){
            if(x.second > maxCnt){
                isTop = false;
                maxCnt = x.second;
                maxEle = x.first;
            }
        }
        return isTop ? getAnswer(top, bot, maxEle, ans) : getAnswer(bot, top, maxEle, ans);
        
    }
};
