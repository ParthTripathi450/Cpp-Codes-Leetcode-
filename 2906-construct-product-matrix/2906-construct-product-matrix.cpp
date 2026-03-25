class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<int> temp;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp.push_back(grid[i][j]);
            }
        }
        int s=temp.size();
        vector<long long> l(s,1);
        vector<long long> r(s,1);
        for(int i=1;i<s;i++){
            l[i]=(l[i-1]*temp[i-1])%12345;
        }
        for(int i=s-2;i>=0;i--){
            r[i]=(r[i+1]*temp[i+1])%12345;
        }
        for(int i=0;i<s;i++){
            temp[i]=(r[i]*l[i])%12345;
        }
        int x=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=temp[x++];
            }
        }
        return grid;
    }
};