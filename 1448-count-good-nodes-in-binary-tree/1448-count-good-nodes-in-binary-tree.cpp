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
    int dfs(TreeNode* root,int mx){
        if(!root)return 0;

        int good = (root->val>=mx)? 1:0;
        mx = max(root->val,mx);
        
        return good+dfs(root->left,mx) + dfs(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};