class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> charToWord;
        unordered_map<string,char> wordToChar;
        istringstream iss(s);
        vector<string> words;
        string word;

    while (iss >> word) {
        words.push_back(word);
    }

    if (words.size() != pattern.length()) return false;

    for (int i = 0; i < pattern.length(); ++i) {
        char ch=pattern[i];
        string w=words[i];

        if (charToWord.count(ch)) {
            if (charToWord[ch]!=w) return false;
        } else {
            charToWord[ch]=w;
        }

        if (wordToChar.count(w)) {
            if (wordToChar[w]!=ch) return false;
        } else {
            wordToChar[w]=ch;
        }
    }

    return true;
    }
};