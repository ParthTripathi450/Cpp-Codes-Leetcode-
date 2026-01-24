class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> pre(m+1);
        vector<int> cur(m+1);
        for(int i=0;i<=m;i++)
        {
            pre[i]=i;
        }
        for(int i=1;i<=n;i++)
        {
            cur[0]=i;
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    cur[j]=pre[j-1];
                }
                else
                {
                    cur[j]=1+min({pre[j-1],pre[j],cur[j-1]});
                }
            }
            pre=cur;
        }
        return pre[m];
    }
};