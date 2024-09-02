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
        while(k>=chalk[i%n]){
            k-=chalk[i%n];
            i++;
        }
        return i%n;
    }
};