class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    bool atl,pac;
    void dfs(vector<vector<int>>& heights,int r,int c,int prevVal){
        if(r<0 || c<0){
            pac = true;
            return;
        }
        if(r>=heights.size() || c >=heights[0].size()){
            atl=true;
            return;
        }
        if(heights[r][c]>prevVal){
            return;
        }
        int temp = heights[r][c];
        heights[r][c] = INT_MAX;
        for(auto& d:dir){
            dfs(heights,r+d[0],c+d[1],temp);
                if(atl && pac){
                    break;
                }

        }
        heights[r][c] = temp;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int ROWS=heights.size();
        int COLS = heights[0].size();
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                atl=false;
                pac=false;
                dfs(heights,r,c,heights[r][c]);
                if(atl&&pac){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
};