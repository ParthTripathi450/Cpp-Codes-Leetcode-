class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0,sum=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        sum=lsum;
        for(int i=0;i<k;i++){
            lsum-=cardPoints[k-1-i];
            rsum+=cardPoints[cardPoints.size()-1-i];
            sum=max(sum,lsum+rsum);
        }
        return sum;
    }
};