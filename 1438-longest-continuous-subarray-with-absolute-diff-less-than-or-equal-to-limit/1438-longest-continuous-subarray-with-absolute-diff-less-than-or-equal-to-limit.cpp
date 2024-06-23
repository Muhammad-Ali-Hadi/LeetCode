class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // First Approach
        
        // int maxLength=0;
        // int currMax=nums.front(),currMin=nums.front();
        // for(int i=0,j=0;i<nums.size();++i)
        // {
        //     currMax=max(currMax,nums[i]);
        //     currMin=min(currMin,nums[i]);
        //     while(currMax-currMin>limit)
        //     {
        //         ++j;
        //         currMax=*max_element(nums.begin()+j,nums.begin()+i+1);
        //         currMin=*min_element(nums.begin()+j,nums.begin()+i+1);
        //     }
        //     maxLength=max(maxLength,i-j+1);
        // }
        // return maxLength;

        vector<int> maxList,minList;
        int maxLength=0;
        for(int i=0,j=0;i<nums.size();++i)
        {  
            while(!maxList.empty() && nums[maxList.back()]<=nums[i])
            {
                maxList.pop_back();
            }
            maxList.push_back(i);
            while(!minList.empty() && nums[minList.back()]>=nums[i])
            {
                minList.pop_back();
            }
            minList.push_back(i);
            while(nums[maxList.front()]-nums[minList.front()]>limit)
            {
                ++j;
                if(maxList.front()<i)
                {
                    maxList.erase(maxList.begin());
                }
                if(minList.front()<i)
                {
                    minList.erase(minList.begin());
                }
            }
            maxLength=max(maxLength,i-j+1);
        }
        return maxLength;
    }
};