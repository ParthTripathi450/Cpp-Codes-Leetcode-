class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_set<char> seen;
        unordered_map<char, int> last_occurrence;

        for (int i = 0; i < s.size(); i++) {
            last_occurrence[s[i]] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (seen.find(ch) == seen.end()) {
                while (!st.empty() && st.top() > ch && last_occurrence[st.top()] > i) {
                    seen.erase(st.top());
                    st.pop();
                }
                st.push(ch);
                seen.insert(ch);
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};