class Solution {
public:
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     int i=0;
    //     while(i<s.size()){
    //         for(const string& word:wordDict){
    //             if(i+word.length()<=s.size() &&
    //             s.substr(i,i+word.length()) == word){
    //                     i+=word.length();
    //             }
    //             else{
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    unordered_map<int,bool> memo;

    bool dfs(string s,vector<string>& wordDict,int i){
        if(memo.find(i) != memo.end())return memo[i];
        if(i == s.size())return true;
        for(const string &word:wordDict){
            if(i+word.length()<=s.size() &&
            s.substr(i,word.length()) == word){
                if(dfs(s,wordDict,i+word.length())){
                    memo[i] = true;
                    return memo[i];
                }
            }
        }
        memo[i] = false;
        return memo[i];
    }
    bool wordBreak(string s, vector<string>& wordDict){
        return dfs(s,wordDict,0);
    }
};