class Solution {
public:
    int minPartitions(string n) {
       int mexi=0; 
       for(char ch: n)
       {
        mexi=max(mexi,(ch-'0'));
       }
        return mexi;
        
    }
};