class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<long long> current(points[0].size(),0);
        vector<long long> previous(points[0].size(),0);
        
        for(long long j=0;j<points[0].size();++j)
        {
            previous[j]=points[0][j];
        }

        for(long long i=1;i<points.size();++i)
        {
            for(long long j=0;j<points[i].size();++j)
            {
                long long maxVal=previous[j];
                for(long long k=0;k<points[i].size();++k)
                {
                    maxVal=max(maxVal,points[i][j]+previous[k]-abs(j-k));
                }
                current[j]=maxVal;
            }
            previous=current;
        }

        long long maxVal=previous[0];
        for(long long i=1;i<previous.size();++i)
        {
            if(previous[i]>maxVal)
            {
                maxVal=previous[i];
            }
        }
        return maxVal;
    }
};