class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long int m=grid.size();
        long long int n=grid[0].size();
        long long int total=0;
        for(long long int i=0;i<m;i++){
            for(long long int j=0;j<n;j++){
                total+=grid[i][j];
            }
        }
        long long int sum=0;
        for(long long int j=0;j<n-1;j++){
            for(long long int i=0;i<m;i++){
                sum+=grid[i][j];
            }
            if(2*sum==total){
                return true;
            }
        }
        sum=0;
        for(long long int i=0;i<m-1;i++){
            for(long long int j=0;j<n;j++){
                sum+=grid[i][j];
            }
            if(2*sum==total){
                return true;
            }
        }
        return false;
    }
};