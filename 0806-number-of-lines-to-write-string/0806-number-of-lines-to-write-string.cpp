class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int sum = 0; 
        int cnt = 0; 
       
        for( int i = 0; i<s.length(); i++)
        {
              int index = s[i] - 'a';
               sum += widths[index];
              if(sum > 100){
                cnt++;
                sum -= widths[index];
                sum = 0; 
                sum = widths[index];
              }
        }
        if(sum) cnt++;
        return {cnt,sum};
    }
};