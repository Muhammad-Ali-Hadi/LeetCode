class Solution {
    vector<vector<int>> result; 
public:
    vector<vector<int>> permute(vector<int>& nums,int l=0) {
        if(nums.size()==1)
        return {{nums.front()}};

        if(l==nums.size()-1)
        {
            result.push_back(nums);
            return result;
        }

        for(int i=l;i<nums.size();++i)
        {
            swap(nums[l],nums[i]);
            permute(nums,l+1);
            swap(nums[l],nums[i]); // Backtract to Update to the Original Array
        }
        return result;
    }
};