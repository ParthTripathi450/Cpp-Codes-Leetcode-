class Solution {
public:
    string processStr(string s) {
        string res="";
        for(char c:s){
            if(c>='a' && c<='z'){
                res += c;
            }else if(c == '*' && res.size()!=0){
                res.erase(res.size()-1);//delete last character
            }else if(c=='#'){
                res +=res;
            }else{
                reverse(res.begin(),res.end());
            }
        }
        return res;

    }
};
