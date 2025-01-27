class Solution {
public:
    int searchInsert(vector<int>& nums, int target,int left=0,int right=-1) {
        if(nums.empty())
        return -1;
        
        // if(right==-1)
        // right=nums.size()-1;

        // if(left>right)
        // return left;

        // int mid=left+(right-left)/2;

        // if(nums[mid]==target)
        // return mid;

        // if(nums[mid]>target)
        // return searchInsert(nums,target,left,mid-1);
        // else
        // return searchInsert(nums,target,mid+1,right);

        right=nums.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(nums[mid]==target)
            return mid;

            if(nums[mid]>target)
            right=mid-1;
            else
            left=mid+1;
        }
        return left;
    }
};