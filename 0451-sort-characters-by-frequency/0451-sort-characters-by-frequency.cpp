class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mpp;
        string res="";
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int count=0;
        char store=' ';
        while(!mpp.empty()){
            for(auto itr : mpp){
                if(itr.second>count){
                    store=itr.first;
                    count=itr.second;
                }
            }
            for(int j=0;j<count;j++){
                res+=store;
            }
            mpp.erase(store);
            count=0;
            store=' ';
        }
        return res;
    }
};