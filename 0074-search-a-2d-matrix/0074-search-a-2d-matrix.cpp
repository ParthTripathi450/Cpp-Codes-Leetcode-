class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int level=n-1;
        for(int i=0;i<n;i++){
            if(matrix[i][0]<= target && matrix[i][m-1]>=target){
                level = i;
                break;
            }
        }
        int left = 0;
        int right = m-1;
        int mid;
        while(left<=right){
            mid = (left+right)/2;
            if(matrix[level][mid] == target)return true;
            else if(matrix[level][mid]<target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return false;
    }
};