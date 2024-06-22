class Solution {
public:
    int gcd(int num1,int num2)
    {
        if(num1==0)
        return num2;
        else if(num2==0)
        return num1;
        else if(num1>num2)
        return gcd(num1%num2,num2);
        else if(num2>num1)
        return gcd(num1,num2%num1);
        return num1;
    }
    int findGCD(vector<int>& nums) {
        // sort(nums.begin(),nums.begin());
        // int left=0;
        // int right=nums.size()-1;
        // bool flag=true;
        // int n=1;
        // while(flag)
        // {
        //     if(!(nums[right]%nums[left]))
        //     {
        //         return gcd(nums[left],nums[right]);
        //     }
        //     if(left==right-1)
        //     {
        //         left=n;
        //         ++n;
        //     }
        //     if(n==right-1)
        //     {
        //         --right;
        //         n=0;
        //         left=0;
        //     }
        // }
        // return -1;

        sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();++i)
        // {
        //     for(int j=nums.size()-1;j>=0;--j)
        //     {
        //         if(!(nums[j]%nums[i]))
        //         {
        //             return gcd(nums[i],nums[j]);
        //         }
        //     }
        // }
        return gcd(nums.front(),nums.back());
    }
};