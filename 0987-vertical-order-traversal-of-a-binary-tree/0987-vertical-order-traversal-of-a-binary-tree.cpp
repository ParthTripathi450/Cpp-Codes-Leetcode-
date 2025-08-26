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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Store nodes as {col, row, val}
        vector<tuple<int,int,int>> nodes;
        dfs(root, 0, 0, nodes);

        // Sort by (col, row, val)
        sort(nodes.begin(), nodes.end(), [](auto &a, auto &b) {
            if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
            if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
            return get<2>(a) < get<2>(b);
        });

        // Group by col
        vector<vector<int>> ans;
        int prevCol = INT_MIN;
        for (auto &[c, r, v] : nodes) {
            if (c != prevCol) {
                ans.push_back({});
                prevCol = c;
            }
            ans.back().push_back(v);
        }
        return ans;
    }

private:
    void dfs(TreeNode* node, int row, int col, vector<tuple<int,int,int>> &nodes) {
        if (!node) return;
        nodes.push_back({col, row, node->val});
        dfs(node->left, row+1, col-1, nodes);
        dfs(node->right, row+1, col+1, nodes);
    }
};