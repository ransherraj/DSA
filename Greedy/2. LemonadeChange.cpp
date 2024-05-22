// Greedy 2
//https://leetcode.com/problems/lemonade-change/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5 = 0, cnt10 = 0, cnt20 = 0, lemonadeCost = 5;
        for(int i = 0; i<bills.size(); i++){
            if(bills[i] == lemonadeCost)
            {
                cnt5++;
            }
            else if(bills[i] == 2*lemonadeCost)
            {
                cnt10++;
                if(cnt5 > 0)
                {
                    cnt5--;
                }
                else
                {
                    return false;
                }
                    
            }
            else
            {
                cnt20++;
                if(cnt10 > 0 && cnt5 > 0) 
                {
                    cnt5--;
                    cnt10--;
                }
                else if(cnt5 >= 3)
                {
                    cnt5 -= 3;
                }
                else 
                {
                    return false;
                }
            }
        }    
        return true;
    }
};
