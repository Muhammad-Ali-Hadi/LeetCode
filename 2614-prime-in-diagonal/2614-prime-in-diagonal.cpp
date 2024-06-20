class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        vector<int> num;
        for(int i=0;i<nums.size();++i)
        {
            // for(int j=0;j<nums[i].size();++j)
            // {
            //     if(i==j || (i==0 && j==nums.size()-1) || (i==nums.size()-1 && j==0))
            //     num.push_back(nums[i][j]);
            // }
            num.push_back(nums[i][i]);
            if(i!=nums.size()-i-1)
            num.push_back(nums[i][nums.size()-i-1]);
        }
        sort(num.begin(),num.end());
        int max=0;
        for(int i=0;i<num.size();++i)
        {
            bool flag=true;
            for(int j=2;j*j<=num[i];++j)
            {
                if(num[i]%j==0)
                {
                    flag=false;
                    break;
                }
            }
            if(flag && num[i]>max && num[i]>1)
            max=num[i];
        }
        return max;
    }
};