#define speed ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define fori(x,n) for(int i=x;i<n;++i)
#define forj(y,m) for(int j=y;j<m;++j)

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        speed;

        vector<vector<int>> res(n,vector<int>(n));
        int num=1;
        fori(0,(n+1)/2)
        {
            forj(i,n-i)
            {
                res[i][j]=num++;
            }

            forj(i+1,n-i)
            {
                res[j][n-i-1]=num++;
            }

            for(int j=n-i-2;j>=i;--j)
            {
                res[n-i-1][j]=num++;
            }

            for(int j=n-i-2;j>i;--j)
            {
                res[j][i]=num++;
            }
        }
        return res;
    }
};