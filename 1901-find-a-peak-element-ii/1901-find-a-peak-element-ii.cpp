class Solution {
public:
    int findmax(vector<vector<int>>& mat, int col) {
        int maxi = 0;
        int max_index=0;
        for (int i = 0; i < mat.size(); i++) {
            if(mat[i][col] > maxi){
                max_index=i;
                // cout<<" i = "<<i<<"\t";
                maxi=mat[i][col];
            }
        }
        return max_index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat[0].size();
        int n = mat.size();
        int start = 0;
        int end = m - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            // cout<<mid;
            int maxrow=findmax(mat,mid);
            // cout<<" "<<maxrow<<endl;
            int left = mid-1 >=0 ? mat[maxrow][mid-1] : -1;
            int right = mid+1 <= m-1 ? mat[maxrow][mid+1] : -1;
            if(mat[maxrow][mid] > left && mat[maxrow][mid] > right){
                return {maxrow,mid};

            }else if( mat[maxrow][mid] < left){
                end=mid-1;
            }else{
                start=mid+1;
            }

        }
        return {-1,-1};

    }
};