class Solution {
public:
    int firstDigit(int num)
    {
        return (num<10) ? num : firstDigit(num/10);
    }

    int countBeautifulPairs(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-1;++i)
        {
            for(int j=i+1;j<nums.size();++j)
            {
                if(gcd(firstDigit(nums[i]),(nums[j]%10))==1)
                ++count;
            }
        }
        return count;
    }
};