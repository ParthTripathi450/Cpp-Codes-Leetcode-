class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        vector<long long>timing(n,0);
        for(int i = 0 ; i < mana.size(); i++){
           long long   prev = timing[0];
            for(int j = 0 ;j < skill.size() ; j++){
                if(j > 0)
                {
                prev = max(timing[j-1], timing[j]);
                prev = prev + (long long)(skill[j]*mana[i]);
            }
                else
                {
                prev = timing[j];

                prev = (prev +(long long) (skill[j]*mana[i]));
                }
                timing[j] = prev;

            }
            if(i > 0){
            for(int k = n-2; k>= 0  ; k--){
                timing[k] = timing[k+1]-(long long)(skill[k+1]*mana[i]);
            }
            }
        }
        return timing[n-1];
    }
};
