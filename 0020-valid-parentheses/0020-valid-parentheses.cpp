class Solution {
public:
    bool isValid(string s) {
        stack <int> stk;
        map <char,char> mpp = {{'(',')'},{'{','}'},{'[',']'}};
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' ) stk.push(s[i]);
            else{
                if(stk.empty())return false;
                else if(s[i] == mpp[stk.top()] )stk.pop();
                else{
                    return false;
                }
            }
        }
        if(stk.empty()) return true;
        return false;  
    }
};