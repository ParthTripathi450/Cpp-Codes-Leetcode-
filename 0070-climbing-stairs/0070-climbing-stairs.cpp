class Solution {
public:
    int solve(int n){
        if(n==0) return 1;
        else if (n==1) return 1;
        int left = solve(n-1);
        int right = solve(n-2);
        return left+right;
    }
    int climbStairs(int n) {
        return solve(n);
    }
};