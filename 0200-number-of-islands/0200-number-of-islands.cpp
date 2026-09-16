class Solution {
public:
    int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int ROWS;
    int COLS;

    void bfs(vector<vector<char>>& grid,int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx = x + dir[k][0];
                int ny = y + dir[k][1];

                if(nx>= 0 && nx <ROWS &&
                   ny>=0  && ny <COLS &&
                   grid[nx][ny]=='1'){
                    q.push({nx,ny});
                    grid[nx][ny] = '0';
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        ROWS = grid.size();
        COLS = grid[0].size();
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(grid[i][j] == '1'){
                    bfs(grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};