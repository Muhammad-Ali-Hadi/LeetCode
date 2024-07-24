class Solution {
public:
    vector<int> convert(vector<int>& mapping,vector<int>& nums)
    {
        vector<int> newSystem(nums.size());
        for(int i=0;i<nums.size();++i)
        {
            int num=nums[i];
            if(num==0)
            {
                newSystem[i]=mapping[0];
                continue;
            }
            int n=0;
            int result=0;
            while(num>0)
            {
                int digit=num%10;
                int newDigit=mapping[digit];
                result+=newDigit*pow(10,n++);
                num/=10;
            }
            newSystem[i]=result;
        }
        return newSystem;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> newSystem=convert(mapping,nums);
        vector<int> index(nums.size());
        for(int i=0;i<nums.size();++i)
        {
            index[i]=i;
        }
        sort(index.begin(),index.end(),[&](int a,int b)
        {
            return newSystem[a]-newSystem[b];
        });
        vector<int> result(nums.size());
        for(int i=0;i<index.size();++i)
        {
            result[i]=nums[index[i]];
        }
        return result;      
    }
};