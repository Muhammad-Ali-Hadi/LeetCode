#define speed ios_base::sync_with_stdio(false),cin.tie(nullptr)

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        speed;

        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            int res=-1;
            int d=1;
            while((nums[i]&d))
            {
                res=nums[i]-d;
                d<<=1;
            }
            nums[i]=res;
        }
        return nums;
    }
};