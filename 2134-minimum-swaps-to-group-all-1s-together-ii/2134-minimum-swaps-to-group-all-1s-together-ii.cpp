class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i])
            ++totalOnes;
        }

        vector<int> extended(2*nums.size());
        for(int i=0;i<nums.size();++i)
        {
            extended[i]=nums[i];
            extended[i+nums.size()]=nums[i];
        }

        int currentOnes=0;
        for(int i=0;i<totalOnes;++i)
        {
            if(extended[i])
            ++currentOnes;
        }

        int maxWindow=currentOnes;
        for(int i=totalOnes;i<2*nums.size();++i)
        {
            if(extended[i])
            ++currentOnes;
            if(extended[i-totalOnes])
            --currentOnes;
            maxWindow=max(maxWindow,currentOnes);
        }
        return totalOnes-maxWindow;
    }
};