#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        fast;

        int ind1=-1,ind2=-1;
        for(int i=nums.size()-2;i>=0;i+=-1)
        {
            if(nums[i]<nums[i+1])
            {
                ind1=i;
                break;
            }
        }

        if(ind1==-1)
        reverse(nums.begin(),nums.end());
        else
        {
            for(int i=nums.size()-1;i>=0;i+=-1)
            {
                if(nums[i]>nums[ind1])
                {
                    ind2=i;
                    break;
                }
            }
            swap(nums[ind1],nums[ind2]);
            reverse(nums.begin()+ind1+1,nums.end());
        }
    }
};