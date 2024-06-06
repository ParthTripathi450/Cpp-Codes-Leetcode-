class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=1,crnprofit=0,profit=0;
        while(r<prices.size()){
            if(prices[r]>prices[l]){
                crnprofit=prices[r]-prices[l];
                profit=max(profit,crnprofit);
            }
            else if(prices[l]>prices[r]){
                l=r;
            }
            r+=1;
        }
        return profit;
    }
};