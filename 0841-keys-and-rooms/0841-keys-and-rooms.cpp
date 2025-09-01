class Solution {
public:
    void dfs(int room,vector<bool>&visited,vector<vector<int>>& rooms){
        visited[room] = true;
        for(int key:rooms[room]){
            if(!visited[key]){
                dfs(key,visited,rooms);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        dfs(0,visited,rooms);
        for(bool v:visited){
            if(!v)return false;
        }
        return true;
    }
};