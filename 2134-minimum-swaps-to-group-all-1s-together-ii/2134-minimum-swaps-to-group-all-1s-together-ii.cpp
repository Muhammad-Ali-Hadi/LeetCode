class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i])
            ++totalOnes;
        }

        vector<int> extendedNums(2*nums.size());
        for(int i=0;i<nums.size();++i)
        {
            extendedNums[i]=nums[i];
            extendedNums[i+nums.size()]=nums[i];
        }

        int maxOnesWindow=0,currentOnes=0;
        for(int i=0;i<totalOnes;++i)
        {
            if(nums[i])
            ++currentOnes;
        }
        maxOnesWindow=currentOnes;
        for(int i=totalOnes;i<2*nums.size();++i)
        {
            if(extendedNums[i])
            ++currentOnes;
            if(extendedNums[i-totalOnes])
            --currentOnes;

            maxOnesWindow=max(maxOnesWindow,currentOnes);
        }
        return totalOnes-maxOnesWindow;
    }
};