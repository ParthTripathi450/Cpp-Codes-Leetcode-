class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        stack <int> stk;
        while(i < pushed.size()){
            stk.push(pushed[i]);
            cout<<"Pushed: ";
            cout<<stk.top()<<endl;
            while(stk.top() == popped[j] ){
                j++;
                cout<<"Popped: ";
                cout<<stk.top()<<endl;
                stk.pop();
                cout<<"i: ";
                cout<<i<<endl;
                if(stk.empty()){
                    if(i>=pushed.size()-1){
                        return true;
                    }
                    break;
                }
                //if(stk.empty() && i>=1) return true;
            }
            i++;
        }
        return false;
        // while( !stk.empty() ){
        //     if(stk.top()!=popped[j]){
        //         return false;
        //     }
        //     stk.pop();
        //     j++;
        // }
        // return true;
    }
};