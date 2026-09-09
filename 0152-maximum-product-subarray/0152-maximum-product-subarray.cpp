class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax=1;
        int currMin = 1;
        int res=INT_MIN;
        for(int num : nums){
            if(num == 0){
                currMax = 1;
                currMin = 1;
            }
            int temp = currMax*num;
            currMax = max(max(num,currMax*num),currMin*num);
            currMin = min(min(num,temp),currMin*num);
            res = max(res,currMax);
        }
        return res;
    }
};