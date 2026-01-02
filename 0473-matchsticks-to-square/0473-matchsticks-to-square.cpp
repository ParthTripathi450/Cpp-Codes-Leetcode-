class Solution {
public:
    bool dfs(int idx,vector<int>& sticks,vector<int>& sides,int target){
        if(idx == sticks.size()) return true;
        for(int i=0;i<4;i++){
            if(sides[i] + sticks[idx] > target){
                continue;
            }
            sides[i] += sticks[idx];
            if(dfs(idx+1,sticks,sides,target))return true;
            sides[i] -= sticks[idx];
            if(sides[i] == 0)break;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int total=0;
        for(int x : matchsticks)total+=x;
        if(total%4 != 0) return false;

        int side = total/4;
        sort(matchsticks.rbegin(),matchsticks.rend());

        if(matchsticks[0] > side) return false;

        vector<int> sides(4,0);
        return dfs(0,matchsticks,sides,side);
    }
};