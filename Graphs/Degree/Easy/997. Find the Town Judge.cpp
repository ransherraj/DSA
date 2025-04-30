/*

997. Find the Town Judge
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
 

Constraints:

1 <= n <= 1000
0 <= trust.length <= 104
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n

*/

// Solution 1 : concept of indegree outdegree at a node. If indegree at anode is 0 and outdegree is n-1, then that node is accepted as JUDGE

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans = -1;
        vector<int> indegree(n+1, 0), outdegree(n+1, 0);
        for(auto x : trust){
            indegree[x[0]]++;
            outdegree[x[1]]++;
        }
        for(int i = 1; i<=n; i++){
            if(indegree[i] == 0 && outdegree[i] == n-1) return i;
        }
        return ans;
    }
};

// solution 2 : Concept to find equivalent degree of each node by adding substracting indegree and adding outdegree. Equivalent should again be n-1.
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans = -1;
        vector<int> degree(n+1, 0);
        for(auto x : trust){
            degree[x[0]]--;
            degree[x[1]]++;
        }
        for(int i = 1; i<=n; i++){
            if(degree[i] == n-1) return i;
        }
        return ans;
    }
};
