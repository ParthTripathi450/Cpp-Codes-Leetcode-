class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i=0;
        int n = chalk.size();
        long long total = 0;
        for(int i: chalk){
            total+=i;
        }
        k = k%total;
        cout<<k<<endl;
        for(int j = 0;j<n;j++){
            if(chalk[j]>k){
                cout<<j;
                return j;
            }
            k -= chalk[j];
        }
        return 0;
    }
};