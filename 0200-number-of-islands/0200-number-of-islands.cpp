class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int ROWS,COLS;
    int islands;
    void dfs(vector<vector<char>>& grid,int r,int c){
        if(r<0 || r>=ROWS || c<0 || c>=COLS ||grid[r][c] == '0'){
            return;
        }
        grid[r][c] = '0';
        for(int i=0;i<4;i++){
            dfs(grid,r + dir[i][0],c + dir[i][1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        islands=0;
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if(grid[r][c] == '1'){
                    dfs(grid,r,c);
                    islands++;
                }
            }
        }
        return islands;
    }
};