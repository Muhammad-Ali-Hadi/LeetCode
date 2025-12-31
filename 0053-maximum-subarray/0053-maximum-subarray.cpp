#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        fast;

        int curr=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            curr=max(nums[i],curr+nums[i]);
            ans=max(ans,curr);
        }
        return ans;
    }
};