class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0; 
        int mini = prices[0];
        int ans=INT_MIN;
        int cost;
        for(int i=1;i<prices.size();i++){
            mini = min(mini,prices[i]);
            if(cost <prices[i] - mini)cost = prices[i] - mini;
            cout<<cost<<" ";
        }
        return cost;
    }
};