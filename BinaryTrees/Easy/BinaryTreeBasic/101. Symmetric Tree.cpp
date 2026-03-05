/*****


Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 


****/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isMirror(TreeNode* l, TreeNode* r){
        if(l == NULL && r == NULL) return true;
        if(l == NULL || r == NULL) return false;
        return (l->val == r->val) && isMirror(l->left, r->right) && isMirror(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        return isMirror(l, r);
    }
};
