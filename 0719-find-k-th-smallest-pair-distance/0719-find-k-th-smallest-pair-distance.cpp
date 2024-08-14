class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> diff;
        for(int i=0;i<nums.size();++i)
        {
            for(int j=i+1;j<nums.size();++j)
            {
                diff.push_back(nums[j]-nums[i]);
            }
        }
        sort(diff.begin(),diff.end());
        return diff[k-1];
    }
};