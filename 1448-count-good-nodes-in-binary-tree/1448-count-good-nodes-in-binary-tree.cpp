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
    void calmax(TreeNode* root, int max, int &count)
    {
        if (root == NULL) 
        {
            return;
        }
        if (root->val >= max) 
        {
            max = root->val;
            count++;
            cout << max << " " << count << endl;
        }
        calmax(root->left, max, count);
        calmax(root->right, max, count);
    }
    int goodNodes(TreeNode* root) 
    {

        if (root == NULL) 
        {
            return 0;
        }
        int count = 0;
        int max = INT_MIN;

        calmax(root, max, count);

        return count;
    }
};