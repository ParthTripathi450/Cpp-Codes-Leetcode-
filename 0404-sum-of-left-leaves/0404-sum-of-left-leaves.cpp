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
bool isLeaf(TreeNode* node) {
    return (node != nullptr && node->left == nullptr && node->right == nullptr);
}

int sumOfLeftLeaves(TreeNode* root) {
    if (root==nullptr) return 0;

    int sum = 0;
    if (isLeaf(root->left)) {
        sum += root->left->val;
    }
    sum+=sumOfLeftLeaves(root->left);
    sum+=sumOfLeftLeaves(root->right);
    return sum;
}
};