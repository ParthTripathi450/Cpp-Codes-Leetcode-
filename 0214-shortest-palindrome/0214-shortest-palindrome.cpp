class Solution {
public:
    string shortestPalindrome(string s) {
        long long prefix = 0;
        long long suffix = 0;
        long long base = 29;
        long long power = 1;
        long long mod = 10000007;

        int last_index = -1;

        for(int i=0;i<s.size();i++){
            int ch = (s[i] - 'a' + 1);

            prefix = (prefix * base) % mod;
            prefix = (prefix+ch) % mod;

            suffix = (suffix + ch * power) %mod;

            power = (power * base) % mod;

            if(prefix == suffix){
                last_index = i;
            }
        }

        string suffixStr = s.substr(last_index + 1);
        reverse(suffixStr.begin(),suffixStr.end());

        return suffixStr + s;
    }

};