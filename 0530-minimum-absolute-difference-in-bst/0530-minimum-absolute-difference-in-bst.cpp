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
    int prevVal=-1;
    int minDiffVal=INT_MAX;
    void minDiff(int value){
        if(prevVal!=-1){
            int currDiff=value-prevVal;
            if(currDiff<minDiffVal){
                minDiffVal = currDiff;
            }
        }
        prevVal=value;
    }
    void inOrder(TreeNode* root){
        if(!root)return;
        inOrder(root->left);
        minDiff(root->val);
        inOrder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return minDiffVal;
    }
};