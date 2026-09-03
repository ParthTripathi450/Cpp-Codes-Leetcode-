class Solution {
public:
    unordered_map <int, bool> memo;
    bool dfs(string& s,vector<string>& wordDict,int i){
        if(memo.find(i) != memo.end())return memo[i];
        if ( i == s.length())return true;
        for(const string& w:wordDict){
            if(i + w.length() <= s.length() && s.substr(i,w.length()) == w){

                    if(dfs(s,wordDict,i+w.length())){
                        memo[i] = true;
                        return memo[i];
                    }
            }
        }
        memo[i] = false;
        return memo[i];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memo[s.length()] = true;
        return dfs(s,wordDict,0);
    }
};