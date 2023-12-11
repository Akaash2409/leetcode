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
    bool hasPathSum(TreeNode* root, int tsum) {
        if(root==nullptr) return false;

        tsum-=root->val;
        if(root->left==nullptr && root->right==nullptr && tsum==0) return true;

        return hasPathSum(root->left,tsum) || hasPathSum(root->right,tsum);

    }
};