class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp=matrix;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                temp[j][matrix.size()-i-1]=matrix[i][j];
            }
        }
        matrix=temp;
    }
};