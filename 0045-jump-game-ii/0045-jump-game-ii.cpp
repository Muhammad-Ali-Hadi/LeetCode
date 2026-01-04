#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr)

class Solution {
public:
    int jump(vector<int>& nums) {
        fast;

        vector<int> dp(nums.size(),-1);
        function<int(int)>f=[&](int i)->int{
            if(i>=nums.size())
            return 1e9;

            if(i==nums.size()-1)
            return 0;

            if(dp[i]==-2)
            return 1e9;

            if(dp[i]!=-1)
            return dp[i];
            
            dp[i]=-2;
            int ans=1e9;
            if(nums[i]<nums.size())
            ans=min(ans,1+f(nums[i]));

            if(nums[i]<nums.size() && nums[nums[i]]<nums.size())
            ans=min(ans,1+f(nums[nums[i]]));

            ans=min(ans,1+f(i+1));
            return dp[i]=ans;
        };
        return f(0)-1;
    }
};