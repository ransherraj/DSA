/**




**/

class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& sizeOfCookies) {
        int i = 0, j = 0;
        sort(greed.begin(), greed.end());
        sort(sizeOfCookies.begin(), sizeOfCookies.end());
        int n = greed.size();
        int m = sizeOfCookies.size();
        while(i < n && j < m){
            if(greed[i] <= sizeOfCookies[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};
