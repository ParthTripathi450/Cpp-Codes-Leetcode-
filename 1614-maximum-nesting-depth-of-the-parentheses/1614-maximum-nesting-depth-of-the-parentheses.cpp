class Solution {
public:
    int maxDepth(string s) {
        int bal=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                bal++;
                if(bal>count){
                    count=bal;
                }
            }
            else if(s[i]==')'){
                bal--;
            }
        }
        return count;    
    }
};