class Solution {
public:
    long long rangeSum(vector<int>& nums,long long n,long long left,long long right) {
        vector<long long> arr;
        for(long long i=0;i<n;++i)
        {
            long long sum=0;
            for(long long j=i;j<n;++j)
            {
                sum+=nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(),arr.end());
        long long result=0;
        for(long long i=left-1;i<right;++i)
        {
            result+=arr[i];
        }
        return result;
    }
};