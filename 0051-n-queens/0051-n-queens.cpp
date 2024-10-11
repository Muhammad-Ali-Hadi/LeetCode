class Solution {
    vector<string> grid;
    vector<vector<string>> result;
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n==1)
        return {{"Q"}};
        
        auto isSafe=[&](int x,int y)->bool
        {
            for(int i=0;i<x;++i)
            {
                if(grid[i][y]=='Q')
                return false;
            }

            int row=x;
            int col=y;

            while(row>=0 && col>=0)
            {
                if(grid[row][col]=='Q')
                return false;

                --row,--col;
            }

            row=x;
            col=y;

            while(row>=0 && col<grid.size())
            {
                if(grid[row][col]=='Q')
                return false;

                --row,++col;
            }
            return true;
        };

        grid.resize(n,string(n,'.'));

        function<void(int)>NQueens=[&](int row)->void
        {
            if(row==n)
            {
                result.push_back(grid);
                return;
            }

            for(int i=0;i<n;++i)
            {
                if(isSafe(row,i))
                {
                    grid[row][i]='Q';

                    NQueens(row+1);
                    
                    grid[row][i]='.';
                }
            }
        };

        NQueens(0);
        return result;
    }
};