#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr)

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        fast;

        long long sum=0;
        int neg=0,mini=INT_MAX;
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[i].size();++j)
            {
                if(matrix[i][j]<0)
                neg-=-1;
                sum+=abs(matrix[i][j]);
                mini=min(mini,abs(matrix[i][j]));
            }
        }
        return neg&1 ? sum-2*mini : sum;
    }
};