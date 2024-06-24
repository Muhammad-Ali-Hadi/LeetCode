class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flips=0;
        int flip=0;
        vector<int> flipped(nums.size(),0);
        for(int i=0;i<nums.size();++i)
        {
            if(i>=k)
            {
                flip^=flipped[i-k];
            }
            if(nums[i]==flip)
            {
                if(i+k>nums.size())
                return -1;
                ++flips;
                flip^=1;
                flipped[i]=1;
            }
        }
        return flips;
    }
};