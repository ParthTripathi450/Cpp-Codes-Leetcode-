class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>res;
        sort(potions.begin(),potions.end());
        int m=spells.size();
        int n=potions.size();
        
        for(int i=0; i<m; i++){
            int put=0;
            int low=0;
        int high=n-1;
        
            while(low<=high){
                int mid=low+(high-low)/2;
                if(((long)spells[i]*potions[mid])>=success){
                    put=put+high-mid+1;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            res.push_back(put);
        }
        return res;
        
    }
};