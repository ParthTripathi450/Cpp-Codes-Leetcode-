class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        int m = matrix[0].size()-1;
        int bottom=0,top=matrix.size()-1;
        int left=0, right = matrix[0].size()-1;
        vector<int> ans;
        while(bottom<= top && left<=right){
            for(int i=left;i<=right;i++){
                ans.emplace_back(matrix[bottom][i]);
            }
            bottom++;
            for(int i=bottom;i<=top;i++){
                ans.emplace_back(matrix[i][right]);
            }
            right--;
            if(bottom<=top){
                for(int i=right;i>=left;i--){
                    ans.emplace_back(matrix[top][i]);
                }
            }
            top--;
            if(left<=right){
                for(int i=top;i>=bottom;i--){
                    ans.emplace_back(matrix[i][left]);
                }
            }
            left++;
        }
        return ans;
        
    }
};