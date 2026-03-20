class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n-k+1, vector<int>(m-k+1));

        for (int i = 0; i <= n-k; i++) {
            for (int j = 0; j <= m-k; j++) {

                // Collect all k*k elements in this window
                vector<int> Element;
                for (int row = i; row < i+k; row++)
                    for (int col = j; col < j+k; col++)
                        Element.push_back(grid[row][col]);

                // Sort so duplicates are adjacent, then remove them
                sort(Element.begin(), Element.end());
                Element.erase(unique(Element.begin(), Element.end()), Element.end());

                // Only 1 unique value → diff is 0
                if (Element.size() <= 1) { res[i][j] = 0; continue; }

                // Walk sorted array: check each adjacent pair
                int diff = INT_MAX;
                for (int x = 0; x < (int)Element.size()-1; x++)
                    diff = min(diff, Element[x+1] - Element[x]);

                res[i][j] = diff;
            }
        }
        return res;
    }
};