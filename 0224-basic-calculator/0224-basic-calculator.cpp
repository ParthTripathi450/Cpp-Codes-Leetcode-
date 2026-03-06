class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        long long num = 0;
        long long res=0;
        long long sign = 1;
        for(char c: s){
            if(c == ' '){
                continue;
            }
            else if(isdigit(c)){
                num = num*10 + (c-'0');
            }
            else if(c == '+'){
                res+= sign*num;
                sign = 1;
                num=0;
            }
            else if(c == '-'){
                res+= sign*num;
                sign = -1;
                num = 0;
            }
            else if(c == '('){
                stk.push(res);
                stk.push(sign);
                
                res=0;
                sign=1;
                
            }
            else if(c == ')'){
                res+= sign*num;
                num = 0;
                long long prev_sign = stk.top(); stk.pop();
                long long prev_res = stk.top(); stk.pop();
                
                res = prev_res + prev_sign*res;
            }
        }
        res += sign*num;
        return res;
    }
};