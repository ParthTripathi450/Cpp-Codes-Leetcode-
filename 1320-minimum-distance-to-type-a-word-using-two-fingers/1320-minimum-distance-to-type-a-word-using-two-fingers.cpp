class Solution {
private:
    vector<vector<vector<int>>> dp;
    int solve(int i, int n, int f1, int f2, string& s) {
        if (i == n)
            return 0;

        if (dp[i][f1][f2] != -1)
            return dp[i][f1][f2];

        int ans = INT_MAX;

        int x = (s[i] - 'A') / 6;
        int y = (s[i] - 'A') % 6;

        int cost1 = 0;
        if (f1 != 26) {
            int x2 = f1 / 6;
            int y2 = f1 % 6;

            cost1 = abs(x - x2) + abs(y - y2);
        }
        ans = min(ans, cost1 + solve(i + 1, n, s[i] - 'A', f2, s));

        int cost2 = 0;
        if (f2 != 26) {
            int x2 = f2 / 6;
            int y2 = f2 % 6;

            cost2 = abs(x - x2) + abs(y - y2);
        }
        ans = min(ans, cost2 + solve(i + 1, n, f1, s[i] - 'A', s));

        return dp[i][f1][f2] = ans;
    }

public:
    int minimumDistance(string word) {
        int n = word.size();

        int f1 = 26;
        int f2 = 26;

        dp.resize(n, vector<vector<int>>(27, vector<int>(27, -1)));

        return solve(0, n, f1, f2, word);
    }
};