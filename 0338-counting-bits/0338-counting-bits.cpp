class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int num=0;num<=n;num++){
            int numdot=0;
            for(int j=0;j<32;j++){
                res[num]+=((1<<j)&num)?1:0;
            }
        }
        return res;
    }
};