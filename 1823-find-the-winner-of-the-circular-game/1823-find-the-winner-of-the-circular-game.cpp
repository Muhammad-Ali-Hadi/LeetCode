class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums(n);
        for(int i=0;i<n;++i)
        {
            nums[i]=i+1;
        }
        int index=0;
        while(nums.size()>1)
        {
            int nextIndex=(index+k-1)%nums.size();
            nums.erase(nums.begin()+nextIndex);
            index=nextIndex;
        }
        return nums[0];
    }
};