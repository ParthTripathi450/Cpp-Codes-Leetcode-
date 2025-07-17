class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int i=0;
        while(i<s.size()){
            if(mpp[s[i]] == 1)return i;
            i++;
        }
        return -1;
    }
};