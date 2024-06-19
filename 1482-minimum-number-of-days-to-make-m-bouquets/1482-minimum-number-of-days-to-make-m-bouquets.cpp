class Solution {
public:
    int minDays(vector<int>& bloomDay,long long int m,long long int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        long long int n=bloomDay.size();
        if(n<m*k)
        return -1;
        long long int left=bloomDay[0];
        for(int i=1;i<bloomDay.size();++i)
        {
            if(left>bloomDay[i])
            left=bloomDay[i];
        }
        long long int right=bloomDay[0];
        for(int i=1;i<bloomDay.size();++i)
        {
            if(right<bloomDay[i])
            right=bloomDay[i];
        }
        while(left<right)
        {
            long long int mid=left+(right-left)/2;
            long long int bouquets=0;
            long long int flowers=0;
            for(int i=0;i<bloomDay.size();++i)
            {
                if(bloomDay[i]<=mid)
                {
                    ++flowers;
                    if(flowers==k)
                    {
                        ++bouquets;
                        flowers=0;
                    }
                }
                else
                flowers=0;
            }
            if(bouquets>=m)
            right=mid;
            else
            left=mid+1;
        }
        return left;
    }
};