class Solution {
public:
    void back(vector<string>& ans, map<int, vector<char>> dail, string& digits,
              string& str, int pos) {

        if (pos == digits.length()) {
            if (str.length() >= 1)
                ans.push_back(str);
            return;
        }
     
        int  num = digits[pos] - '0';
        
        for (int i = 0; i < dail[num].size(); i++) {
            str.push_back(dail[num][i]);
            back(ans, dail, digits, str, pos+1);
            str.pop_back();
        }
    }


 vector<string> letterCombinations(string digits) {
    map<int, vector<char>> map1;
    map1[2] = {'a', 'b', 'c'};
    map1[3] = {'d', 'e', 'f'};
    map1[4] = {'g', 'h', 'i'};
    map1[5] = {'j', 'k', 'l'};
    map1[6] = {'m', 'n', 'o'};
    map1[7] = {'p', 'q', 'r', 's'};
    map1[8] = {'t', 'u', 'v'};
    map1[9] = {'w', 'x', 'y', 'z'};

    vector<string> ans;
    string str = "";
    if (digits.length() > 0)
        back(ans, map1, digits, str, 0);
    else
        return ans;

    return ans;
}
}
;