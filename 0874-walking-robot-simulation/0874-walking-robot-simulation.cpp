class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        char dir = 'N';
        int maxi = 0;

        unordered_set<string> obstacleSet;
        for (auto& obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }

        for(auto &i : commands){
            if(i != -1 && i != -2){
                for(int step = 0; step < i; step++){
                    int X = x, Y = y;
                    if(dir == 'N'){
                        Y++;
                    }
                    if(dir == 'E'){
                        X++;
                    }
                    if(dir == 'S'){
                        Y--;
                    }
                    if(dir == 'W'){
                        X--;
                    }
                    if (obstacleSet.count(to_string(X) + "," + to_string(Y))) {
                            break;
                    }

                    x = X;
                    y = Y;
                    int dist = x*x + y*y;
                    maxi = max(maxi,dist);
                }
            }
            if(i == -1){
                if(dir == 'N'){
                    dir = 'E';
                }
                else if(dir == 'E'){
                    dir = 'S';
                }
                else if(dir == 'S'){
                    dir = 'W';
                }
                else if(dir == 'W'){
                    dir = 'N';
                }
            }
            else if(i == -2){
                if(dir == 'N'){
                    dir = 'W';
                }
                else if(dir == 'E'){
                    dir = 'N';
                }
                else if(dir == 'S'){
                    dir = 'E';
                }
                else if(dir == 'W'){
                    dir = 'S';
                }
            }
        }
        return maxi;
    }
};