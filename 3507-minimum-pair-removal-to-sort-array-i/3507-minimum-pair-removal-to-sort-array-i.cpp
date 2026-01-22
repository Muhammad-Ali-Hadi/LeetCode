#define speed ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define forn(x,n) for(int i=x;i<n;++i)

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        speed;

        int cnt=0;

        while(nums.size()>1)
        {
            bool f=true;
            int minSum=numeric_limits<int>::max();
            int ind=-1;

            for(int i=0;i<nums.size()-1;++i)
            {
                int sum=nums[i]+nums[i+1];

                if(nums[i]>nums[i+1])
                f=false;

                if(sum<minSum)
                {
                    minSum=sum;
                    ind=i;
                }
            }
            if(f)
            break;

            cnt++;
            nums[ind]=minSum;
            nums.erase(nums.begin()+ind+1);
        }
        return cnt;
    }
};