class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int maxlen1=0;
        int maxlen2=0;
        int maxlen3=1;
        int maxlen4=1;
        //Case1:
        int i=0;
        while(i<nums.size()){
            if(nums[i]%2==0){
                maxlen1++;
            }
            i++;
        }
        //case2
        i=0;
        while(i<nums.size()){
            if(nums[i]%2!=0){
                maxlen2++;
            }
            i++;
        }
        //Case3
        if(nums[0]%2==0){
            bool checker=false;
            i=1;
            while(i<nums.size()){
                if(checker==false && nums[i]%2!=0){
                    checker=true;
                    maxlen3++;
                }
                else if(checker==true && nums[i]%2==0){
                    checker=false;
                    maxlen3++;
                }
                i++;
            }
        }
        //Case4
        else if(nums[0]%2!=0){
            bool checker=true;
            i=1;
            while(i<nums.size()){
                if(checker==false && nums[i]%2!=0){
                    checker=true;
                    maxlen4++;
                }
                else if(checker==true && nums[i]%2==0){
                    checker=false;
                    maxlen4++;
                }
                i++;
            }
        }
        return max(maxlen1,max(maxlen2,max(maxlen3,maxlen4)));
    }
};