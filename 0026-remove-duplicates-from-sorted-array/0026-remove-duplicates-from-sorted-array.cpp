class Solution {
public:
    int removeDuplicates(vector<int>& nums,int i=1) {
        // int n=1;
        // for(int i=1;i<nums.size();++i)
        // {
        //     if(nums[i]!=nums[i-1])
        //     nums[n++] = nums[i];
        // }
        // return n;

        if(i==nums.size())
        return nums.size();

        if(nums[i]==nums[i-1])
        {
            nums.erase(nums.begin()+i);
            return removeDuplicates(nums,i);
        }
        else
        return removeDuplicates(nums,i+1);
    }
};