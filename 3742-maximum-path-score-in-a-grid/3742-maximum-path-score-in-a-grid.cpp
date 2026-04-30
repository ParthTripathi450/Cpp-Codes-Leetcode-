class Solution {
public:
    int m , n;
    int solve(vector<vector<int>>& grid , int k , int i , int j , int cst , vector<vector<vector<int>>>& memo) {
        if (i >= m || j >= n) return INT_MIN;

        int newCst = cst + (grid[i][j] > 0);
        if (newCst > k) {
            return INT_MIN;
        }

        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (memo[i][j][cst] != -1) {
            return memo[i][j][cst];
        }

        int down = solve(grid , k , i + 1 , j , newCst , memo);
        int right = solve(grid , k , i , j + 1 , newCst , memo);

        int best = max(right , down);

        if (best == INT_MIN) {
            return memo[i][j][cst] = INT_MIN;
        }

        return memo[i][j][cst] = grid[i][j] + best;
    } 

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> memo(m + 1 , vector<vector<int>>(n + 1 , vector<int>(k + 1 , -1)));

        int maxScore = solve(grid , k , 0 , 0 , 0 , memo);

        return maxScore == INT_MIN ? -1 : maxScore;
    }
};