class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        if (start == goal) return cnt;
        int s=start^goal;
        for (int i=0;i<32;i++){
            if(s&(1<<i)) cnt++;
        }
        return cnt;
    }
};