#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr)

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        fast;

        int ans=0;
        for(int i=0;i<nums.size();++i)
        {
            int sum=0,cnt=0;
            for(int j=1;j*j<=nums[i];++j)
            {
                if(nums[i]%j==0)
                {
                    int x=nums[i]/j;

                    sum+=j;
                    ++cnt;

                    if(x!=j)
                    {
                        sum+=x;
                        ++cnt;
                    }

                    if(cnt>4)
                    break;
                }
            }
            if(cnt==4)
            ans+=sum;
        }
        return ans;
    }
};