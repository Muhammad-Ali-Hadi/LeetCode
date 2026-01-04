#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        fast;

        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        
        for(int i=0;i<nums.size()-3;++i)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;

            for(int j=i+1;j<nums.size()-2;++j)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                continue;

                long long int newTarget=(long long int)target-nums[i]-nums[j];

                int l=j+1,r=nums.size()-1;
                while(l<r)
                {
                    long long int sum=(long long int)nums[l]+nums[r];

                    if(sum==newTarget)
                    {
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});

                        while(l+1<r && nums[l]==nums[l+1]) ++l;
                        while(l<r-1 && nums[r]==nums[r-1]) --r;

                        ++l,--r; 
                    }
                    else if(sum>newTarget)
                    --r;
                    else
                    ++l; 
                }
            }
        }
        return ans;
    }
};