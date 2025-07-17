class Solution {
public:
    bool isPerfectSquare(int num) {
        long long res=(long long)sqrt(num);
        return res*res==num;
    }
};