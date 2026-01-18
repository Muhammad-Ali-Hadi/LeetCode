#define speed ios_base::sync_with_stdio(false),cin.tie(nullptr)

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        speed;

        int ans=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> prefRows(m+2,vector<int>(n+2,0)),prefCols(prefRows),prefD1(prefRows),prefD2(prefRows);

        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                prefRows[i][j]+=grid[i-1][j-1]+prefRows[i][j-1];
                prefCols[i][j]+=grid[i-1][j-1]+prefCols[i-1][j];
                prefD1[i][j]+=grid[i-1][j-1]+prefD1[i-1][j-1];
                prefD2[i][j]+=grid[i-1][j-1]+prefD2[i-1][j+1];
            }
        }

        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                for(int k=min(m-i,n-j);k>ans;--k)
                {
                    int sum=prefD1[i+k][j+k]-prefD1[i-1][j-1];
                    bool f=sum==prefD2[i+k][j]-prefD2[i-1][j+k+1];
                    for(int l=0;l<=k && f;++l)
                    {
                        f&=sum==prefRows[i+l][j+k]-prefRows[i+l][j-1];
                        f&=sum==prefCols[i+k][j+l]-prefCols[i-1][j+l];
                    }
                    ans=f ? k : ans;
                }
            }
        }
        return ans+1;
    }
};