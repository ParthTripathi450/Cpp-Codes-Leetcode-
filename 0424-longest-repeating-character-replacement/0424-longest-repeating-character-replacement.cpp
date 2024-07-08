class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf=0,maxlen=0,changes=0;
        map <char,int> mpp;
        int l=0,r=0;
        while(r<s.size()){
            mpp[s[r]]++;
            maxf=max(maxf,mpp[s[r]]);
            changes=r-l+1-maxf;
            if(changes<=k){
                maxlen=max(maxlen,r-l+1);
            }
            else{
                mpp[s[l]]--;
                l++;
            }
            r++;
        }
        return maxlen;
    }

};