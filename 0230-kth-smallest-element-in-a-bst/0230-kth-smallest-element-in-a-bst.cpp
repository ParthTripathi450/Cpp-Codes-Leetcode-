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
    int ans, count = 0;
    void inorder(TreeNode* root, int k){
        if(!root)return;
        inorder(root->left,k);
        if(++count == k){
            ans = root->val;
            return;
        }
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k){
        inorder(root,k);
        return ans;
    }
    // int kthSmallest(TreeNode* root, int k) {
    //     stack<TreeNode*> st;
    //     TreeNode* curr = root;
    //     while(curr!=nullptr || !st.empty()){
    //         while(curr != nullptr){
    //             st.push(curr);
    //             curr = curr->left;
    //         }
    //         curr = st.top();
    //         st.pop();
    //         if(--k == 0)return curr->val;
    //         curr = curr->right;
    //     }
    //     return -1;
    // }
};