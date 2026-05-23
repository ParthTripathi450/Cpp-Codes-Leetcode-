class Solution {
public:

    int minimumDifference(vector<int>& nums) {

        int n = nums.size()/2;

        vector<int> left(nums.begin(),nums.begin()+n);
        vector<int> right(nums.begin()+n,nums.end());

        int total = accumulate(nums.begin(),nums.end(),0);

        vector<vector<int>> leftSum(n+1),rightSum(n+1);

        for(int mask=0;mask<(1<<n);mask++){

            int cnt = 0;
            int lsum = 0;
            int rsum = 0;

            for(int i=0;i<n;i++){

                if(mask&(1<<i)){
                    cnt++;
                    lsum += left[i];
                    rsum += right[i];
                }
            }

            leftSum[cnt].push_back(lsum);
            rightSum[cnt].push_back(rsum);
        }

        for(int i=0;i<=n;i++){
            sort(rightSum[i].begin(),rightSum[i].end());
        }

        int ans = INT_MAX;

        for(int k=0;k<=n;k++){

            for(int lsum:leftSum[k]){

                int target = total/2 - lsum;

                auto& vec = rightSum[n-k];

                auto it =lower_bound(vec.begin(),vec.end(),target);
                if(it!=vec.end()){
                    int sum1=lsum + *it;
                    int sum2=total - sum1;
                    ans=min(ans,abs(sum1-sum2));
                }
                if(it!=vec.begin()){
                    --it;
                    int sum1=lsum+ *it;
                    int sum2=total-sum1;

                    ans=min(ans,abs(sum1-sum2));
                }
            }
        }

        return ans;
    }
};