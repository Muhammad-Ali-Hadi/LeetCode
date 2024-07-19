class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> nums;
        for(int i=0;i<matrix.size();++i)
        {
            int min=matrix[i][0];
            int minIndex=0;
            for(int j=1;j<matrix[i].size();++j)
            {
                if(matrix[i][j]<min)
                {
                    min=matrix[i][j];
                    minIndex=j;
                }
            }
            bool flag=true;
            for(int j=0;j<matrix.size();++j)
            {
                if(matrix[j][minIndex]>min)
                {
                    flag=false;
                    break;
                }
            }

            if(flag)
            {
                nums.push_back(min);
            }
        }
        return nums;
    }
};