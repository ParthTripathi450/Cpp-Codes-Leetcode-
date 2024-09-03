class Solution {
public:
    int getLucky(string s, int k) {
        string num;

        for(int i=0;i<s.length();i++)
        {
            int o=s[i]-96;
            string y=to_string(o);
            num+=y;   
        }
        long long sum = 0;
        for (char c : num) {
            sum += c - '0';  
        }
        int y=sum;
        for(int i=1;i<k;i++)
        {       
            sum=0;
            while(y!=0)
            {
                int rem=y%10;
                sum+=rem;
                y/=10;
            }
            y=sum;
        }
        return sum;
    }
};