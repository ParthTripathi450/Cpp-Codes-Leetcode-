class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> validWordFrequency;

        string word;
        string result;
        int maxCount=0;

        for(int i=0; i<=paragraph.size(); i++){
            if(isalpha(paragraph[i])){ 
            word+=tolower(paragraph[i]);
            }else if(!word.empty()){
                if(bannedSet.find(word)==bannedSet.end()){
                    validWordFrequency[word]++;
                }
                if(validWordFrequency[word]>maxCount){
                    maxCount=validWordFrequency[word];
                    result = word;
                }
                word="";
            }
        }
        return result;
    }
};