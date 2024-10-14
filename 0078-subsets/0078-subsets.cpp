class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        function<void(int)>backtrack=[&](int start)->void
        {
            res.push_back(subset);
            for(int i=start;i<nums.size();++i)
            {
                subset.push_back(nums[i]);
                backtrack(i+1);
                subset.pop_back();
            }
        };

        backtrack(0);
        return res;
    }
};