class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int num;
        vector<int> even1(26, 0),even2(26,0);
        vector<int> odd1(26, 0),odd2(26,0);
        for(int i=0;i<s1.size();i++){
            if(i%2==0){
                even1[s1[i]-'a']++;
            }
            else odd1[s1[i]-'a']++;
        }
        for(int i=0;i<s2.size();i++){
            if(i%2==0){
                even2[s2[i]-'a']++;
            }
            else odd2[s2[i]-'a']++;
        }
        if((even1==even2)&&(odd1==odd2))return true;
        return false;

    }
};