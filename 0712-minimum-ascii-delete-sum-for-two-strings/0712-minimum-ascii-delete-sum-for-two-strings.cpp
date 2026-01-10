#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr)

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        fast;

        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));

        function<int(int,int)>f=[&](int i,int j)->int{
            if(i==n || j==m)
            return 0;

            if(dp[i][j]!=INT_MAX)
            return dp[i][j];

            return dp[i][j]=s1[i]==s2[j] ? s1[i]+f(i+1,j+1) : max(f(i+1,j),f(i,j+1));
        };
        int tot=0;
        for(int i=0;i<n;++i)
        {
            tot+=s1[i];
        }
        for(int i=0;i<m;++i)
        {
            tot+=s2[i];
        }
        return tot-2*f(0,0);
    }
};