class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        stack <int> stk;
        while(i < pushed.size()){
            stk.push(pushed[i]);
            while(stk.top() == popped[j] ){
                j++;
                stk.pop();
                if(stk.empty()){
                    if(i>=pushed.size()-1){
                        return true;
                    }
                    break;
                }
            }
            i++;
        }
        return false;
    }
};