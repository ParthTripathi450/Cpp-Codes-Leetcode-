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
    int dfs(TreeNode* root, long long sum, int target,
            unordered_map<long long,int>& mp) {
        
        if(!root) return 0;

        sum += root->val;
        int ans = 0;
        if(mp.count(sum - target))
            ans += mp[sum - target];
        mp[sum]++;
        ans+=dfs(root->left,sum,target, mp);
        ans+=dfs(root->right,sum,target, mp);
        mp[sum]--;
        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mp;
        mp[0] = 1;

        return dfs(root, 0, targetSum, mp);
    }
};