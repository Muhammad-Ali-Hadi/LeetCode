class Solution {
public:
    bool isValid(int i,int j,vector<vector<int>>& grid)
    {
        vector<int> count(10,0);
        for(int k=0;k<3;++k)
        {
            for(int m=0;m<3;++m)
            {
                int num=grid[i+k][j+m];
                if(num<1 || num>9 || count[num]>0)
                return false;
                count[num]++;
            }
        }
        int sum=grid[i][j]+grid[i][j+1]+grid[i][j+2];

        for(int k=0;k<3;++k)
        {
            if(sum!=grid[i+k][j]+grid[i+k][j+1]+grid[i+k][j+2])
            return false;
        }

        for(int k=0;k<3;++k)
        {
            if(sum!=grid[i][j+k]+grid[i+1][j+k]+grid[i+2][j+k])
            return false;
        }

        if(sum!=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2])
        return false;
        if(sum!=grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2])
        return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count=0;
        int row=grid.size();
        int column=grid[0].size();
        if(row<3 || column<3)
        return 0;

        for(int i=0;i<=row-3;++i)
        {
            for(int j=0;j<=column-3;++j)
            {
                if(isValid(i,j,grid))
                ++count;
            }
        }
        return count;
    }
};