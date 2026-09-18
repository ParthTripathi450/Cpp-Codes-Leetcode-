class Solution {
public:
    int maxiVal(vector<int>& piles){
        int val=INT_MIN;
        for(int i=0;i<piles.size();i++){
            val = max(val,piles[i]);
        }
        return val;
    }
    double checker(vector<int>& piles,int div){
        int n = piles.size();
        double totalHours=0;
        for(int i=0;i<n;i++){
            totalHours += ceil( (double)piles[i] / (double)div ) ;
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h){
        int low = 1;
        int high = maxiVal(piles);
        int mid;
        int ans=high;
        while(low<=high){
            mid = (low+high)/2;
            if(checker(piles,mid) <= h){
                ans = mid;
                cout<<ans<<" ";
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

};