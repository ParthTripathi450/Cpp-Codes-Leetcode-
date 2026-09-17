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
    int ans;
    int cnt;
    void inorder(TreeNode* node,int k){
        if(!node)return;
        inorder(node->left,k);
        cnt++;
        if(cnt==k){
            ans = node->val;
            return;
        }
        inorder(node->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return -1;
        cnt=0;
        inorder(root,k);
        return ans;
    }
};