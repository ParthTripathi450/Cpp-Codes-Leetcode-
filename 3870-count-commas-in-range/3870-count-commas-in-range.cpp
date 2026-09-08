class Solution {
public:
    int countCommas(int n) {
        if(n<1000)return 0;
        int res=0;
        int sum=1;
        sum += n%1000;
        int factor = floor(n/1000);
        factor--;
        sum = sum + (factor*1000);
        return sum;
    }
};