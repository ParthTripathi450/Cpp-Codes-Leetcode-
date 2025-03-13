class Solution {
public:
    int mySqrt(int x) {
        int lo=0;
        int hi=x;
        while(lo<=hi){
            int mid=lo + (hi-lo)/2;
            if(1LL *mid*mid==x){
                return mid;
            }
            else if(1LL *mid*mid>x){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return hi;
    }
};