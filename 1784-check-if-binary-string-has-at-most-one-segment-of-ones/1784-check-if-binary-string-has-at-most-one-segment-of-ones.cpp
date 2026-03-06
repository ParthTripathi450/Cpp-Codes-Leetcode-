class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.length()<=1)return true;
        bool flag = true;
        int i=0;
        while(i<s.length()){
            if(s[i]=='1'){
                if(!flag)return false;
                while(s[i]=='1' && i<s.length()){
                    i++;
                }
                flag=false;
            }
            i++;
        } 
        return true;
    }
};