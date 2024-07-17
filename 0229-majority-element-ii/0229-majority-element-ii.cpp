class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(cnt1==0 && nums[i]!=ele2) {
                cnt1=1;
                ele1=nums[i];
            } else if(cnt2==0 && nums[i]!=ele1) {
                cnt2=1;
                ele2=nums[i];
            } else if(nums[i] == ele1) {
                cnt1++;
            } else if(nums[i] == ele2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]==ele1) cnt1++;
            if(nums[i]==ele2) cnt2++;
        }
        vector<int> vec;
        int mini = nums.size()/3;
        if(cnt1 > mini) vec.push_back(ele1);
        if(cnt2 > mini && ele2!=ele1) vec.push_back(ele2);
        return vec;
    }
};
