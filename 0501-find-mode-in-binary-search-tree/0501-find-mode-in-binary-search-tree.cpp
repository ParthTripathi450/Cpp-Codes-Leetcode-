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
    vector<int> modes;
    int currentVal;
    int maxCount=0;
    int currentCount=0;
    void handleMode(int value){
        if(value!=currentVal){
            currentVal=value;
            currentCount=0;
        }
        currentCount++;
        if(currentCount==maxCount){
            modes.push_back(currentVal);
            maxCount = currentCount;
        }
        if(currentCount>maxCount){
            modes.clear();
            modes.push_back(currentVal);
            maxCount = currentCount;
        }

    }
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        handleMode(root->val);
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
};