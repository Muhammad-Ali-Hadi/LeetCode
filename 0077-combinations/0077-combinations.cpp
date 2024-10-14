class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> combine(int n, int k,int l=0) {
        vector<int> comb;

        function<void(int,vector<vector<int>>&,vector<int>&,int,int)>backtrack=[&backtrack](int start,vector<vector<int>>& result,vector<int>& comb,int n,int k)->void
        {
            if(comb.size()==k)
            {
                result.push_back(comb);
                return;
            }

            for(int i=start;i<=n;++i)
            {
                comb.push_back(i);
                backtrack(i+1,result,comb,n,k);
                comb.pop_back();
            }
        };

        backtrack(1,result,comb,n,k);
        return result;
    }
};