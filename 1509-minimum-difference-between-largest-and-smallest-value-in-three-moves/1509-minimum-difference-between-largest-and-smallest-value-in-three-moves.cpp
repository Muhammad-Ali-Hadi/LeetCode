class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4)
        return 0;

        sort(nums.begin(),nums.end());
        int minDiff=INT_MAX;
        minDiff=min(minDiff,nums[nums.size()-4]-nums[0]);
        minDiff=min(minDiff,nums[nums.size()-3]-nums[1]);
        minDiff=min(minDiff,nums[nums.size()-2]-nums[2]);
        minDiff=min(minDiff,nums[nums.size()-1]-nums[3]);
        return minDiff;
    }
};